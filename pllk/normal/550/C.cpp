#include <iostream>

using namespace std;

string s;

bool ok(int x) {
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i]-'0' == x%10) {
            x /= 10;
        }
        if (x == 0) return true;
    }
    return false;
}

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            cout << "YES\n";
            cout << 0 << "\n";
            return 0;
        }
    }
    for (int i = 8; i < 1000; i += 8) {
        if (ok(i)) {
            cout << "YES\n";
            cout << i << "\n";
            return 0;
        }
    }
    cout << "NO\n";
}