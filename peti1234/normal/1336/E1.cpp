#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, m, s, db, mod=998244353, cnt[36], dp[36][1<<15][36], h[36];
vector<ll> sz;
ll lsb(ll a) {
    return (a&(-a));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> s;
        for (ll i:sz) {
            if (s&lsb(i)) {
                s^=i;
            }
        }
        if (s) {
            for (int i=0; i<sz.size(); i++) {
                if (lsb(s) & sz[i]) {
                    sz[i]^=s;
                }
            }
            sz.push_back(s);
        }
    }
    db=sz.size();
    if (db<=20) {
        for (int i=0; i<(1<<db); i++) {
            ll sum=0;
            for (int j=0; j<db; j++) {
                if (i&(1<<j)) {
                    sum^=sz[j];
                }
            }
            cnt[__builtin_popcountll(sum)]++;
        }
    } else {
        ll f=((ll)1<<m);
        for (int i=0; i<db; i++) {
            h[i]=lsb(sz[i]);
        }
        for (int i=0; i<db; i++) {
            f/=2;
            s=f^h[i];
            for (int j=0; j<db; j++) {
                if (__builtin_popcountll(sz[j]&s)==1) sz[j]^=s;
                if (h[j]&s) h[j]^=s;
            }
        }
        for (int i=0; i<db; i++) {
            s=(sz[i]/f);
            sz[i]%=f;
        }
        dp[0][0][0]=1;
        for (int i=1; i<=db; i++) {
            for (int j=0; j<f; j++) {
                for (int k=0; k<db; k++) {
                    dp[i][j^sz[i-1]][k+1]+=dp[i-1][j][k];
                    dp[i][j][k]+=dp[i-1][j][k];
                }
            }
        }
        for (int j=0; j<f; j++) {
            for (int k=0; k<=db; k++) {
                cnt[__builtin_popcountll(j)+k]+=dp[db][j][k];
            }
        }
    }
    s=1;
    for (int i=1; i<=n-db; i++) {
        s*=2, s%=mod;
    }
    for (int i=0; i<=m; i++) {
        cout << cnt[i]*s%mod << " ";
    }
    return 0;
}