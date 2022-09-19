#include <bits/stdc++.h>

using namespace std;
int n, m;
bool a[501][501];
bool b[501][501];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> b[i][j];
        }
    }
    bool x=true;
    for (int i=1; i<=n; i++) {
        int c=0, d=0;
        for (int j=1; j<=m; j++) {
            if (a[i][j]) {
                c++;
            }
            if (b[i][j]) {
                d++;
            }
        }
        if (c%2!=d%2) {
            x=false;
        }
    }
    for (int i=1; i<=m; i++) {
        int c=0, d=0;
        for (int j=1; j<=n; j++) {
            if (a[j][i]) {
                c++;
            }
            if (b[j][i]) {
                d++;
            }
        }
        if (c%2!=d%2) {
            x=false;
        }
    }
    if (x) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}