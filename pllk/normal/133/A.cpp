#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int v = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'H') v = 1;
        if (s[i] == 'Q') v = 1;
        if (s[i] == '9') v = 1;
    }
    if (v == 0) cout << "NO\n";
    else cout << "YES\n";
}