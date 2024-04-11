#include <iostream>
#include <string>
#include <map>

using namespace std;

string s[8];
map <char, int> base;

int main() {
    base['Q'] = 9;
    base['R'] = 5;
    base['B'] = 3;
    base['N'] = 3;
    base['P'] = 1;
    base['q'] = -9;
    base['r'] = -5;
    base['b'] = -3;
    base['n'] = -3;
    base['p'] = -1;
    for (int i = 0; i < 8; i++) {
        cin >> s[i];
    }
    int balance = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            balance += base[s[i][j]];
        }
    }
    if (balance > 0) {
        cout << "White\n";
    } else if (balance < 0) {
        cout << "Black\n";
    } else {
        cout << "Draw\n";
    }
    return 0;
}