#include <iostream>

using namespace std;

int n;
string s[111];
int a[111];
int b[111];
int c;
int z[111];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') b[j]++;
        }
    }
    c = n;
    while (true) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                z[i] = 1;
                c--;
                ok = false;
                for (int x = 0; x < n; x++) {
                    if (s[i][x] == '1') b[x]--;
                }
            }
        }
        if (ok) break;
    }
    cout << c << "\n";
    for (int i = 0; i < n; i++) {
        if (z[i]) continue;
        cout << i+1 << " ";
    }
    cout << "\n";
}