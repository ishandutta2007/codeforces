#include <bits/stdc++.h>

using namespace std;
bool t[105][105];
void solve() {
    int n, ans=0;
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char c;
            cin >> c;
            t[i][j]=(c=='1');
        }
    }
    for (int i=1; i<=n/2; i++) {
        for (int j=1; j<=n/2; j++) {
            int ert=t[i][j]+t[j][n+1-i]+t[n+1-j][i]+t[n+1-i][n+1-j];
            ans+=min(ert, 4-ert);
        }
    }
    if (n%2) {
        int f=(n+1)/2;
        for (int i=1; i<=n/2; i++) {
            int ert=t[f][i]+t[i][f]+t[f][n+1-i]+t[n+1-i][f];
            ans+=min(ert, 4-ert);
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}