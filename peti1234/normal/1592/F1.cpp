#include <bits/stdc++.h>

using namespace std;
const int c=505;
int n, m, t[c][c], valt[c][c], db[c][c], cnt=0, spec=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            t[i][j]=(c=='B');
        }
    }
    for (int i=n; i>=1; i--) {
        for (int j=m; j>=1; j--) {
            valt[i][j]=(db[i+1][j]+db[i][j+1]+db[i+1][j+1]+t[i][j])%2;
            cnt+=valt[i][j]%2;
            db[i][j]=(db[i+1][j]+db[i][j+1]+db[i+1][j+1]+valt[i][j])%2;
            if (!spec && i<n && j<m && valt[i][j] && valt[i][m] && valt[n][j] && valt[n][m]) {
                spec=1;
                cnt--;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}