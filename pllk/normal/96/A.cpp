#include <iostream>

using namespace std;

string s;

int main() {
    cin >> s;
    char m = 0;
    int t = 0, v = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == m) {
            t++;
            if (t == 7) v = 1;
        } else {
            m = s[i];
            t = 1;
        }
    }
    if (v == 0) cout << "NO\n";
    else cout << "YES\n";
}