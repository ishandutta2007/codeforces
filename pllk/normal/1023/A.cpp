#include <iostream>

using namespace std;

int n, m;
string a, b;

int main() {
    cin >> n >> m;
    cin >> a >> b;
    if (a == b) {
        cout << "YES\n";
        return 0;
    }
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '*') {x++; break;}
        if (i > m-1 || a[i] != b[i]) {
            cout << "NO\n";
            return 0;
        }
        y++;
    }
    int j = m-1;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == '*') {x++; break;}
        if (j < 0 || a[i] != b[j]) {
            cout << "NO\n";
            return 0;
        }
        y++;
        j--;
    }
    if (x == 0 || y > m) cout << "NO\n";
    else cout << "YES\n";
}