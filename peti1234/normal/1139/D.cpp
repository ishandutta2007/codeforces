#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll c=100002;
ll n, mod=1000000007, sum, on, no[c];
vector<ll> oszt[c];
ll dp[c];
ll mo(ll a) {
    ll ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        p/=2, a*=a, a%=mod;
    }
    return ans;
}
ll f(ll a, ll b) {
    ll c=a/b, ans=0;
    ll si=oszt[c].size();
    for (ll i=0; i<(1<<si); i++) {
        int db=0, sz=b, p=i;
        for (int j=0; j<si; j++) {
            if (p%2) db++, sz*=oszt[c][j];
            p/=2;
        }
        if (db%2==0) ans+=n/sz;
        else ans-=n/sz;
    }
    //cout << a << " " << b << " " << ans << endl;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, on=mo(n);
    for (ll i=2; i<=n; i++) {
        if (oszt[i].size()==0) for (ll j=i*i; j<=n; j+=i*i) no[j]=i;
        if (oszt[i].size()==0) for (ll j=i; j<=n; j+=i) oszt[j].push_back(i);
    }
    for (ll i=2; i<=n; i++) {
        if (no[i]) dp[i]=dp[i/no[i]];
        else {
            ll si=oszt[i].size();
            for (ll j=0; j<(1<<si)-1; j++) {
                ll x=j, sz=1, db;
                for (ll k=0; k<si; k++) {
                    ll f=oszt[i][k];
                    if (x%2) sz*=f;
                    x/=2;
                }
                db=f(i, sz);
                dp[i]+=db*dp[sz]%mod, dp[i]%=mod;
            }
            ll x=n-n/i; dp[i]*=mo(x), dp[i]++, dp[i]%=mod;
            /*long long g=x*dp[i];
            long long f=(n+g-x)%mod;
            dp[i]=f*(mo(x))%mod;*/
            dp[i]=(n+x*dp[i]-x)%mod*(mo(x))%mod;
        }
    }
    sum=n;
    for (ll i=1; i<=n; i++) sum+=dp[i], sum%=mod;
    cout << sum*on%mod << "\n";
    return 0;
}