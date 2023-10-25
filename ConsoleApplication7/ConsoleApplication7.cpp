#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;
class Application {
public:
    static Application& GetInstance() {
        static Application instance;
        return instance;
    }

    void StartRandomize() {
        srand(static_cast<unsigned>(time(0)));
    }

    void SetTitle(const  string& title) {
        SetConsoleTitleA(title.c_str());
    }

    void Exit() {
        // Завершение работы
        exit(0);
    }

    void ClearScreen() {
        system("cls");
    }

    void SetTextColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    void Print(const  string& text) {
         cout << text;
    }

private:
    Application() {
        // Инициализация приложения
    }

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
};

int main() {
    Application& app = Application::GetInstance();

    app.SetTitle("My Console App");
    app.StartRandomize();
    app.ClearScreen();
    app.SetTextColor(FOREGROUND_GREEN);
    app.Print("Singleton Application.\n");

    // Пример использования
    for (int i = 0; i < 5; ++i) {
        app.Print("Iteration " +  to_string(i) + "\n");
    }

    //Application obj1; <- создать объект извне нельзя.

    // Завершение работы 
    app.Exit();

    return 0;
}
