#include <bits/stdc++.h>

using namespace std;
long long w, n, t[100005], ans, mod=998244353;
vector<pair<long long, int> > sz[2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sz[n%2].push_back({1, 1});
        for (int i=n-1; i>=1; i--) {
            int a=i%2, b=1-a;
            sz[a].push_back({1, 1});
            for (auto x:sz[b]) {
                long long r=t[i+1]/x.first, ert=(t[i]+r-1)/r;
                ans+=(ert-1)*i%mod*x.second%mod;
                if (sz[a].back().first!=ert) sz[a].push_back({ert, 0});
                sz[a].back().second+=x.second;
            }
            sz[b].clear();
        }
        cout << ans%mod << "\n";
        ans=0, sz[0].clear(), sz[1].clear();
    }
    return 0;
}