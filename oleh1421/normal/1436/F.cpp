
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100100;
const ll mod=998244353;
ll cnt[N];
ll ans[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll f(ll Cnt){
    if (Cnt<=0) return 0;
    return binpow(2,Cnt-1)*((Cnt%mod))%mod;
}
void solve(){
    int m;cin>>m;
    int n=0;
    vector<int>v;
    for (int i=1;i<=m;i++){
        int x;cin>>x;
        cin>>cnt[x];
        n=max(n,x);
        v.push_back(x);
    }
    for (int g=1;g<=n;g++){
        ll Cnt=0ll;
        ll Sum=0ll;
        ll Sum2=0ll;
        for (ll i=g;i<=n;i+=g) {
            Cnt+=cnt[i];
            Sum+=cnt[i]*i;
            Sum2+=cnt[i]*((i*i)%mod);
            Sum%=mod;
            Sum2%=mod;
        }
        ans[g]=0;
        if (Cnt>=1) ans[g]=(ans[g]+f(Cnt-1)*Sum2)%mod;
        if (Cnt>=2) ans[g]=(ans[g]+(f(Cnt-2)+binpow(2,Cnt-2))*(Sum*Sum%mod-Sum2+mod))%mod;
    }
    for (int i:v) cnt[i]=0;
    for (int i=n;i>=1;i--){
        for (int j=i*2;j<=n;j+=i) ans[i]=(ans[i]-ans[j]+mod)%mod;
    }
    cout<<ans[1]<<endl;


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
//1 3 3 4
//0 1 2 3