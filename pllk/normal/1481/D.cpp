#include <iostream>

using namespace std;

string s[1001];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            s[i] = "*"+s[i];
        }
        if (m%2 == 1) {
            cout << "YES\n";
            for (int k = 1; k <= m+1; k++) {
                if (k%2 == 0) cout << 1 << " ";
                else cout << 2 << " ";
            }
            cout << "\n";
            continue;
        }
        int a = 0, b = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (s[i][j] == s[j][i]) {
                    a = i; b = j;
                }
            }
        }
        if (a != 0) {
            cout << "YES\n";
            for (int k = 1; k <= m+1; k++) {
                if (k%2 == 0) cout << a << " ";
                else cout << b << " ";
            }
            cout << "\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            a = 0; b = 0; c = 0;
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (s[i][j] == 'a') a = j;
            }
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (s[j][i] == 'a') b = j;
            }
            if (a && b) {
                c = i;
                break;
            }
        }
        if (c) {
            cout << "YES\n";
            for (int i = 1; i <= m/2+1; i++) {
                if (i%2 == (m/2+1)%2) cout << c << " ";
                else cout << b << " ";
            }
            for (int i = 1; i <= m/2; i++) {
                if (i%2 == 1) cout << a << " ";
                else cout << c << " ";
            }
            cout << "\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            a = 0; b = 0; c = 0;
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (s[i][j] == 'b') a = j;
            }
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (s[j][i] == 'b') b = j;
            }
            if (a && b) {
                c = i;
                break;
            }
        }
        if (c) {
            cout << "YES\n";
            for (int i = 1; i <= m/2+1; i++) {
                if (i%2 == (m/2+1)%2) cout << c << " ";
                else cout << b << " ";
            }
            for (int i = 1; i <= m/2; i++) {
                if (i%2 == 1) cout << a << " ";
                else cout << c << " ";
            }
            cout << "\n";
            continue;
        }
        cout << "NO\n";
    }
}