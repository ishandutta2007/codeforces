// similar to this solution http://codeforces.com/contest/1585/submission/141587730
#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int w, n, fel[c], szint[c];
vector<int> sz[c], dp[c];
set<int> ert[c];
void dfs(int a) {
    szint[a]=(sz[a].size() ? c : 1);
    for (auto x:sz[a]) {
        dfs(x);
        szint[a]=min(szint[a], szint[x]+1);
    }
    if (sz[a].size()==1) {
        int x=sz[a][0];
        swap(dp[a], dp[x]);
        int gr=dp[a].back();
        swap(ert[a], ert[x]);
        while (ert[a].count(gr)) gr++;
        dp[a].push_back(gr);
        ert[a].insert(gr);
    } else {
        dp[a].resize(szint[a]);
        for (int i=1; i<=szint[a]; i++) {
            int p=szint[a]-i;
            for (auto x:sz[a]) {
                dp[a][p]^=dp[x][szint[x]-i+1];
            }
            ert[a].insert(dp[a][p]);
        }
        int gr=0;
        while (ert[a].count(gr)) gr++;
        dp[a].push_back(gr);
        ert[a].insert(gr);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> fel[i];
            if (fel[i]) sz[fel[i]].push_back(i);
        }
        int ans=0;
        for (int i=1; i<=n; i++) {
            if (!fel[i]) {
                dfs(i);
                ans^=dp[i].back();
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
        for (int i=1; i<=n; i++) {
            fel[i]=0, szint[i]=0;
            sz[i].clear(), dp[i].clear();
            ert[i].clear();
        }
    }
    return 0;
}