#include <bits/stdc++.h>

using namespace std;
const long long c=500002;
long long t[c], f[c], h[c], n, m, k, mod=1000000007, ans, db, kul;
vector<pair<long long, pair<long long, long long> > > sz;
vector<long long> hasz;
long long hv(long long a) {
    if (!f[a]) return a;
    long long x=hv(f[a]);
    f[a]=x; return x;
}
void unio(pair<long long, long long> x) {
    long long a=x.first, b=x.second;
    hasz.push_back(a), hasz.push_back(b), a=hv(a), b=hv(b);
    if (a!=b) db++, f[b]=a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k, h[0]=1;
    for (long long i=1; i<=max(n, k); i++) h[i]=h[i-1]*2%mod;
    for (long long i=1; i<=n; i++) cin >> t[i];
    for (long long i=1; i<=m; i++) {
        long long a, b;
        cin >> a >> b;
        sz.push_back({t[a]^t[b], {a, b}});
    }
    sort(sz.begin(), sz.end());
    for (long long i=0; i<m;) {
        long long x=sz[i].first;
        while(i<m && sz[i].first==x) unio(sz[i].second), i++;
        ans+=h[n-db], ans%=mod, kul++;
        for (long long i=0; i<hasz.size(); i++) f[hasz[i]]=0;
        db=0,
        hasz.clear();
    }
    ans+=(h[k]-kul+mod)*h[n], ans%=mod;
    cout << ans << "\n";
    return 0;
}
// minden ll;