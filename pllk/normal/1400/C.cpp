#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        s = "#"+s;
        int x;
        cin >> x;
        string u(n+1,'1');
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                if (i-x >= 1) u[i-x] = '0';
                if (i+x <= n) u[i+x] = '0';
            }
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            char f = '0';
            if (i-x >= 1 && u[i-x] == '1') f = '1';
            if (i+x <= n && u[i+x] == '1') f = '1';
            if (s[i] != f) ok = false;
        }
        if (ok) cout << u.substr(1) << "\n";
        else cout << "-1\n";
    }
}