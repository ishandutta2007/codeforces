#include <iostream>

using namespace std;

string s[8];
int a = 20, b = 20;

int main() {
    for (int i = 0; i < 8; i++) cin >> s[i];
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (s[i][j] == '.') continue;
            if (s[i][j] == 'B') break;
            if (s[i][j] == 'W') a = min(a,i);
        }
        for (int i = 7; i >= 0; i--) {
            if (s[i][j] == '.') continue;
            if (s[i][j] == 'W') break;
            if (s[i][j] == 'B') b = min(b,7-i);
        }
    }
    if (a <= b) cout << "A\n";
    else cout << "B\n";
}