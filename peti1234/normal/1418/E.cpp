#include <bits/stdc++.h>

using namespace std;
const int c=200002, mod=998244353;
long long n, m, s[c], t[c], ks, ns, db, sum;
vector<pair<int, int> > sz;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        p/=2, a*=a, a%=mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m, db=n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        ns+=x, sz.push_back({x, 0});
    }
    for (int i=1; i<=m; i++) {
        int x; cin >> s[i] >> x;
        sz.push_back({x, -i});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<sz.size(); i++) {
        int fi=sz[i].first, se=-sz[i].second;
        if (!se) {
            ns-=fi, ks+=fi, db--;

        } else {
            int x=s[se];
            sum=0;
            if (x<=db) {
                sum+=ks%mod*(db+1-x)%mod*oszt(db+1)%mod;
                sum+=ns%mod*(db-x)%mod*oszt(db)%mod;
            }
            t[se]=sum%mod;
        }
    }
    for (int i=1; i<=m; i++) cout << t[i] << "\n";
    return 0;
}