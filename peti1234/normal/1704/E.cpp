#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int w, n, m, veg;
bool v[c];
vector<int> sz[c];
long long ans, t[c], dp[c], mod=998244353;
void dfs(int a) {
    v[a]=true;
    if (a==veg) {
        dp[a]=1;
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
        dp[a]=(dp[a]+dp[x])%mod;
    }
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b);
        }
        for (int i=1; i<=n; i++) {
            if (sz[i].size()==0) {
                veg=i;
            }
        }
        for (int i=1; i<=n; i++) {
            vector<int> spec;
            for (int j=1; j<=n; j++) {
                if (t[j]) {
                    spec.push_back(j);
                }
            }
            if (spec.size()>0) {
                ans++;
                for (auto x:spec) {
                    t[x]--;
                    for (auto y:sz[x]) {
                        t[y]++;
                    }
                }
            }
        }
        /*for (int i=1; i<=n; i++) {
            cout << i << " " << t[i] << "\n";
        }*/
        if (t[veg]) {
            for (int i=1; i<=n; i++) {
                if (!v[i]) {
                    dfs(i);
                }
                ans=(ans+t[i]*dp[i])%mod;
                //cout << "fontos " << i << " " << t[i] << " " << dp[i] << "\n";
            }
        }
        cout << ans << "\n";

        ans=0, veg=0;
        for (int i=1; i<=n; i++) {
            t[i]=0, dp[i]=0, v[i]=0;
            sz[i].clear();
        }
    }
    return 0;
}
/*
1
6 9
10 10 10 10 10 10
1 2
1 3
2 3
4 3
6 3
3 5
6 5
6 1
6 2
*/