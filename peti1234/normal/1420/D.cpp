#include <bits/stdc++.h>

using namespace std;
long long mod=998244353;
const int c=300002;
long long fakt[c], inv[c], sum;
int n, k, db;
vector<pair<int, int>> sz;
long long oszt(long long a) {
    long long p=mod-2, ans=1;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        a*=a, a%=mod, p/=2;
    }
    return ans;
}
int main()
{
    cin >> n >> k, k--;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
        int x, y; cin >> x >> y;
        sz.push_back({x, 0}), sz.push_back({y, 1});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<2*n; i++) {
        if (sz[i].second==0) db++;
        else {
            db--;
            if (db>=k) sum+=fakt[db]*inv[k]%mod*inv[db-k]%mod, sum%=mod;
        }
    }
    cout << sum << "\n";
    return 0;
}