#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int w, n, m;
bool t[c][c];
bool jo(int a, int b) {
    if (t[a][b]==t[b][a]) {
        for (int i=1; i<=m+1; i++) {
            if (i%2) {
                cout << a << " ";
            } else {
                cout << b << " ";
            }
        }
        cout << "\n";
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int i=1; i<=w; i++) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                char c; cin >> c;
                if (c=='a') {
                    t[i][j]=1;
                }
                if (c=='b') {
                    t[i][j]=0;
                }
            }
        }
        if (n==2 && t[1][2]!=t[2][1] && m%2==0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if (m%2) {
                for (int i=1; i<=m+1; i++) {
                    cout << i%2+1 << " ";
                }
                cout << "\n";
                continue;
            }
            if (jo(1, 2)) {
                continue;
            }
            if (jo(1, 3)) {
                continue;
            }
            if (jo(2, 3)) {
                continue;
            }
            if (t[1][2]==t[2][3] && t[2][3]==t[3][1]) {
                for (int i=1; i<=m+1; i++) {
                    cout << i%3+1 << " ";
                }
                cout << "\n";
                continue;
            }
            int koz=2, k1=1, k2=3;
            if (t[1][2]!=t[1][3]) {
                koz=1, k1=2;
            }
            if (t[2][1]!=t[2][3]) {
                //koz=2;
            }
            if (t[3][1]!=t[3][2]) {
                koz=3, k2=2;
            }
            for (int i=1; i<=m/2; i++) {
                if (i%2) {
                    cout << k1 << " ";
                } else {
                    cout << k2 << " ";
                }
            }
            cout << koz << " ";
            for (int i=m/2+2; i<=m+1; i++) {
                if (i%2) {
                    cout << k2 << " ";
                } else {
                    cout << k1 << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}