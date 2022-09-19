#include <bits/stdc++.h>

using namespace std;
const int c=200002, sok=2e9;
int w, n, szint[c];
long long ert[c], dp[c], kis[c], nagy[c], kisgy[c], nagygy[c], kissz[c], nagysz[c];
vector<int> sz[c], sor;
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sor.clear();
        for (int i=1; i<=n; i++) {
            szint[i]=dp[i]=nagygy[i]=nagysz[i]=0;
            kis[i]=nagy[i]=-sok;
            kisgy[i]=kissz[i]=sok;
            sz[i].clear();
        }
        for (int i=2; i<=n; i++) {
            int x; cin >> x;
            sz[x].push_back(i);
        }
        for (int i=2; i<=n; i++) {
            cin >> ert[i];
        }
        q.push(1), szint[1]=1;
        while (q.size()>0) {
            int id=q.front();
            sor.push_back(id);
            kissz[szint[id]]=min(kissz[szint[id]], ert[id]);
            nagysz[szint[id]]=max(nagysz[szint[id]], ert[id]);
            q.pop();
            for (int x:sz[id]) {
                kisgy[id]=min(kisgy[id], ert[x]);
                nagygy[id]=max(nagygy[id], ert[x]);
                szint[x]=szint[id]+1;
                q.push(x);
            }
        }
        for (int i=n-1; i>=0; i--) {
            int a=sor[i], p=szint[a];
            if (sz[a].size()>0) {
                for (int x:sz[a]) {
                    dp[a]=max(dp[a], dp[x]+max(nagysz[p+1]-ert[x], ert[x]-kissz[p+1]));
                }
                dp[a]=max({dp[a], kis[p+1]+nagygy[a], nagy[p+1]-kisgy[a]});
            }
            kis[p]=max(kis[p], dp[a]-ert[a]);
            nagy[p]=max(nagy[p], dp[a]+ert[a]);
        }
        cout << dp[1] << "\n";
    }
    return 0;
}