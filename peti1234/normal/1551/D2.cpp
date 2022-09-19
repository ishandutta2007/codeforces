#include <bits/stdc++.h>

using namespace std;
int w, n, m, k;
char ans[105][105];
int solve(int a, int b, int c, int d) {
    char x='a'+(a%4)*4+b%4;
    ans[a][b]=x, ans[c][d]=x;
    if (a==c) {
        k--;
    }
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> m >> k;
        if (n%2) {
            for (int j=1; j<m; j+=2) {
                solve(n, j, n, j+1);
            }
        }
        if (m%2) {
            for (int i=1; i<n; i+=2) {
                solve(i, m, i+1, m);
            }
        }
        for (int i=1; i<n; i+=2) {
            for (int j=1; j<m; j+=2) {
                if (k>0) {
                    solve(i, j, i, j+1);
                    solve(i+1, j, i+1, j+1);
                } else {
                    solve(i, j, i+1, j);
                    solve(i, j+1, i+1, j+1);
                }
            }
        }
        cout << (k==0 ? "YES" : "NO") << "\n";
        if (k==0) {
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    cout << ans[i][j];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}