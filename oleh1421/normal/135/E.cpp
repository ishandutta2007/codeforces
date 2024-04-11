//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000100;
const ll mod=1000000007;
ll f[N];
ll rf[N];
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return a*binpow(a,b-1)%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll calc(int k,int w){
    ll res=0ll;
    for (int n=w;n<=w+k;n++){
        if ((n-w)*2<=n){
            ll mult=(f[k]*rf[k+w-n])%mod;
            res+=mult*mult%mod*binpow(k,(2*w-n));
            res%=mod;
        } else {
            int intersect=n-2*w;
            ll mult=(f[k]*rf[k+w-n+intersect])%mod;

            res+=f[k]*f[k-intersect]%mod*rf[k+w-n]%mod*rf[k+w-n];
            res%=mod;
        }
    }
    return res;

}
void solve(){
    int k,w;cin>>k>>w;
    f[0]=1;
    for (ll i=1;i<=k;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[k]=binpow(f[k],mod-2);
    for (ll i=k;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    cout<<(calc(k,w)-calc(k,w-1)+binpow(k,w-1)+mod)%mod;


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
/*

*/