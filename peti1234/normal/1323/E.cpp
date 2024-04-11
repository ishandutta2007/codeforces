#include <bits/stdc++.h>

using namespace std;
const int c=500002;
long long vel() {
    long long a=rand(), b=rand(), c=rand(), d=rand();
    return a*b+c*d;
}
vector<pair<long long, long long> > sz;
int w, n, m;
long long ert[c], h[c], t[c];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> w;
    while(w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) ert[i]=vel();
        sz.clear();
        for (int i=1; i<=n; i++) cin >> t[i], h[i]=0;
        for (int i=1; i<=m; i++) {
            int a, b; cin >> a >> b;
            h[b]+=ert[a];
        }
        for (int i=1; i<=n; i++) {
            if (h[i]) sz.push_back({h[i], t[i]});
        }
        sort(sz.begin(), sz.end());
        long long ans=0, sum=sz[0].second;
        for (int i=1; i<sz.size(); i++) {
            if (sz[i].first!=sz[i-1].first) {
                ans=__gcd(ans, sum);
                sum=0;
            }
            sum+=sz[i].second;
        }
        cout << __gcd(ans, sum) << "\n";
    }
    return 0;
}