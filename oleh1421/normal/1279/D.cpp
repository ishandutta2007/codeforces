#include <bits/stdc++.h>
#define endl '\n'
const long long mod=998244353;
typedef long long ll;
using namespace std;
mt19937_64 rng(time(NULL));
vector<int>g[2000001];
ll cnt[2000001];
ll binpow(ll a,ll b){
    ll res=1ll;
    while (b){
        if (b%2) res=(res*a)%mod;
        b/=2ll;
        a=(a*a)%mod;
    }
    return res;
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        int k;cin>>k;
        for (int j=1;j<=k;j++){
            int x;cin>>x;
            g[i].push_back(x);
            cnt[x]++;
        }
    }
    ll res=0ll;
    ll divN=binpow(n*1ll,mod-2ll);
    for (int i=1;i<=n;i++){
        ll cur=0ll;
        ll divK=binpow((g[i].size())*1ll,mod-2ll);
        for (auto to:g[i]){
            cur+=(cnt[to]*divN);
            cur%=mod;
        }
        cur*=divK;
        cur%=mod;
        res+=(cur*divN);
        res%=mod;
    }
    cout<<res<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}