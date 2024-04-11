#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, t[c][c], valt[c][c], db[c][c], cnt=0, match, par[c];
vector<int> sz[2*c];
bool v[c];
bool dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            v[x]=1;
            if (!par[x] || dfs(par[x])) {
                par[a]=x, par[x]=a;
                return true;
            }
        }
    }
    return false;
}
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
            if (i<n && j<m && valt[i][j] && valt[i][m] && valt[n][j]) {
                sz[i].push_back(j+n);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n+m; j++) {
            v[j]=0;
        }
        match+=dfs(i);
    }
    int spec=(match%2==0 ? 0 : valt[n][m] ? -1 : 1);
    //cout << "vege " << match << "\n";
    cout << cnt-match+spec << "\n";
    return 0;
}