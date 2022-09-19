#include <bits/stdc++.h>

using namespace std;
const int c=3002;
int n, dist[c][c], k[c][c], rf[c], f[c];
long long dp[c][c], maxi;
bool v[c];
vector<int> sz[c];
vector<pair<int, int> > d[c];
void dfs(int a) {
    v[a]=1, rf[a]=1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            for (int i=1; i<=n; i++) if (dist[a][i]) dist[x][i]=dist[a][i]+1;
            f[x]=a, dfs(x), rf[a]+=rf[x];
            for (int i=1; i<=n; i++) if (dist[x][i] && !dist[a][i]) dist[a][i]=dist[x][i]+1;
            dist[a][x]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {int a, b; cin >> a >> b; sz[a].push_back(b), sz[b].push_back(a);}
    dfs(1);
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) if (i!=j && !dist[i][j]) dist[i][j]=dist[j][i];
    for (int i=1; i<=n; i++) dist[i][0]=c, dist[0][i]=c;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int mini=min(rf[i], rf[j]), x=dist[i][j];
            int a=rf[i], b=rf[j];
            if (dist[f[i]][j]>x) for (int p=0; p<sz[i].size(); p++) {
                int q=sz[i][p];
                if (dist[q][j]<x) a=n-rf[q];
            }
            if (dist[f[j]][i]>x) for (int p=0; p<sz[j].size(); p++) {
                int q=sz[j][p];
                if (dist[i][q]<x) b=n-rf[q];
            }
            k[i][j]=a*b;
            d[x].push_back({i, j});
        }
    }
    for (int i=1; i<=n; i++) for (int j=0; j<d[i].size(); j++) {
        int a=d[i][j].first, b=d[i][j].second;
        dp[a][b]+=k[a][b], maxi=max(maxi, dp[a][b]);
        for (int i=0; i<sz[a].size(); i++) {
            int x=sz[a][i];
            dp[x][b]=max(dp[x][b], dp[a][b]);
        }
        for (int i=0; i<sz[b].size(); i++) {
            int x=sz[b][i];
            dp[a][x]=max(dp[a][x], dp[a][b]);
        }
    }
    cout << maxi << "\n";
    return 0;
}