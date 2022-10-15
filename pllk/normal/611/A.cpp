#include <iostream>

using namespace std;

int x;
string s;

int main() {
    cin >> x;
    cin >> s;
    cin >> s;
    if (s == "week") {
        int a = 5;
        int c = 0;
        for (int i = 0; i < 366; i++) {
            if (a == x) c++;
            a++;
            if (a == 8) a = 1;
        }
        cout << c << "\n";
    } else {
        if (x <= 29) cout << "12\n";
        else if (x <= 30) cout << "11\n";
        else cout << "7\n";
    }
}