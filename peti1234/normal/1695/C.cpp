#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, maxi[c][c], mini[c][c];
void solve() {
    cin >> n >> m;
    for (int i=0; i<=max(n, m); i++) {
        mini[0][i]=2*c, maxi[0][i]=-2*c;
        mini[i][0]=2*c, maxi[i][0]=-2*c;
    }
    mini[1][0]=maxi[1][0]=mini[0][1]=maxi[0][1]=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x;
            cin >> x;
            mini[i][j]=min(mini[i][j-1], mini[i-1][j])+x;
            maxi[i][j]=max(maxi[i][j-1], maxi[i-1][j])+x;
            //cout << "ertek " << i << " " << j << " " << mini[i][j] << " " << maxi[i][j] << "\n";
        }
    }
    cout << (maxi[n][m]%2==0 && mini[n][m]<=0 && 0<=maxi[n][m] ? "YES" : "NO") << "\n";
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