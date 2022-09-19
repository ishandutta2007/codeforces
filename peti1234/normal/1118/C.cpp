#include <bits/stdc++.h>

using namespace std;
int n, s=1000, db[1005], ans[25][25], cnt;
void add(int a, int b, int c) {
    if (ans[a][b]) return;
    ans[a][b]=c, db[c]--;
    if (2*a!=n+1) ans[n+1-a][b]=c, db[c]--;
    if (2*b!=n+1) ans[a][n+1-b]=c, db[c]--;
    if (2*a!=n+1 && 2*b!=n+1) ans[n+1-a][n+1-b]=c, db[c]--;
}
int main()
{
    cin >> n;
    for (int i=1; i<=n*n; i++) {
        int x;
        cin >> x;
        db[x]++;
    }
    if (n%2==0) {
        for (int i=1; i<=s; i++) {
            if (db[i]%4) {
                cout << "NO\n";
                return 0;
            }
        }
        for (int i=1; i<=n/2; i++) {
            for (int j=1; j<=n/2; j++) {
                for (int a=1; a<=s; a++) {
                    if (db[a]>=4) {
                        add(i, j, a);
                        continue;
                    }
                }
            }
        }
    } else {
        int f=(n+1)/2;
        for (int i=1; i<f; i++) {
            for (int j=1; j<f; j++) {
                for (int a=1; a<=s; a++) {
                    if (db[a]>=4) {
                        add(i, j, a);
                        continue;
                    }
                }
            }
        }
        for (int x=1; x<f; x++) {
            for (int a=1; a<=s; a++) {
                if (db[a]>=2) {
                    add(x, f, a);
                    continue;
                }
            }
        }
        for (int x=1; x<f; x++) {
            for (int a=1; a<=s; a++) {
                if (db[a]>=2) {
                    add(f, x, a);
                }
            }
        }
        for (int a=1; a<=s; a++) {
            if (db[a]>=1) {
                add(f, f, a);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!ans[i][j]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}