#include <iostream>
#include <algorithm>
using namespace std;
bool u[444];
int a[444][444];
int dp[444][444],n,p,ans;
vector<int> zz[444][444];
int pv[444];
 
void dfs(int x) {
    u[x]=true;
    for (int i=1; i<=n; i++) dp[x][i]=444;
    dp[x][1]=0;
    zz[x][1].resize(0);
    for (int i=1; i<=n; i++) if (!u[i] && a[x][i]) {
        pv[i] = a[x][i];
        dfs(i);
        for (int j=n-1; j>0; j--) if (dp[x][j]<444) {
            for (int k=1; k<=n; k++) if (dp[i][k]+dp[x][j]<dp[x][k+j]) {
              dp[x][k+j]=dp[i][k]+dp[x][j];
              zz[x][k + j] = zz[i][k];
              zz[x][k + j].insert(zz[x][k + j].end(), zz[x][j].begin(), zz[x][j].end());
            }
            dp[x][j]++;
            zz[x][j].push_back(a[x][i]);
        }
    }
}
 
int main() {
    cin >> n >> p;
    int x,y;    
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        a[x][y] = i + 1;
        a[y][x] = i + 1;
    }
    dfs(1);
    ans = dp[1][p];
    vector<int> ansz = zz[1][p];
    for (int i=2; i<=n; i++) {
        if (dp[i][p]+1<ans) {
          ans=dp[i][p]+1;
          ansz = zz[i][p];
          ansz.push_back(pv[i]);
        }
    }
    cout << ans << endl;
    for (int const i : ansz) cout << i << ' ';
    cout << endl;
    return 0;
}