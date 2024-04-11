#include <bits/stdc++.h>

using namespace std;
const int c=62;
int w, n, m, t[c][c], kom[c][c];
bool jo(int a, int b, int c, int d) {
    a--, b--;
    int sum=kom[c][d]-kom[c][b]-kom[a][d]+kom[a][b];
    return (sum==(c-a)*(d-b));
}
bool jo(int a, int b) {
    return (t[a][b]==1);
}
int solve() {
    if (jo(1, 1, n, m)) {
        return 0;
    }
    if (jo(1, 1, 1, m) || jo(1, 1, n, 1) || jo(n, 1, n, m) || jo(1, m, n, m)) {
        return 1;
    }
    if (jo(1, 1) || jo(1, m) || jo(n, 1) || jo(n, m)) {
        return 2;
    }
    for (int i=1; i<=n; i++) {
        if (jo(i, 1, i, m)) {
            return 2;
        }
    }
    for (int j=1; j<=m; j++) {
        if (jo(1, j, n, j)) {
            return 2;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if ((i==1 || i==n || j==1 || j==m) && jo(i, j)) {
                return 3;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (jo(i, j)) {
                return 4;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c;
                cin >> c;
                t[i][j]=(c=='A');
                kom[i][j]=kom[i-1][j]+kom[i][j-1]-kom[i-1][j-1]+t[i][j];
            }
        }
        int s=solve();
        if (s==-1) {
            cout << "MORTAL\n";
        } else {
            cout << s << "\n";
        }
    }
    return 0;
}