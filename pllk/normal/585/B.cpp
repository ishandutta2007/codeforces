#include <iostream>

using namespace std;

int t;
int n, k;

string s[3];
int a[3], b[3];

void solve() {
    cin >> n >> k;
    cin >> s[0] >> s[1] >> s[2];
    s[0] += ".....";
    s[1] += ".....";
    s[2] += ".....";
    a[0] = s[0][0] == 's';
    a[1] = s[1][0] == 's';
    a[2] = s[2][0] == 's';
    for (int i = 0; i < n; i++) {
        //cout << i << s[0] << " " << s[1] << " " << s[2] << "\n";
        b[0] = b[1] = b[2] = 0;
        for (int j = 0; j < 3; j++) {
            if (a[j] == 0) continue;
            if (s[j][i+1] != '.') continue;
            bool ok;
            if (j > 0) {
                ok = true;
                if (s[j-1][i+1] != '.') ok = false;
                if (s[j-1][i+2] != '.') ok = false;
                if (s[j-1][i+3] != '.') ok = false;
                if (ok) b[j-1] = 1;
            }
            ok = true;
            if (s[j][i+2] != '.') ok = false;
            if (s[j][i+3] != '.') ok = false;
            if (ok) b[j] = 1;
            if (j < 2) {
                ok = true;
                if (s[j+1][i+1] != '.') ok = false;
                if (s[j+1][i+2] != '.') ok = false;
                if (s[j+1][i+3] != '.') ok = false;
                if (ok) b[j+1] = 1;
            }
        }
        s[0] = s[0].substr(2) + "..";
        s[1] = s[1].substr(2) + "..";
        s[2] = s[2].substr(2) + "..";
        a[0] = b[0];
        a[1] = b[1];
        a[2] = b[2];
    }
    if (a[0] || a[1] || a[2]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
}