//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const ll mod=998244353ll;
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (binpow(a,b-1)*a)%mod;
    else return binpow((a*a)%mod,b/2ll);
}
ll f[N];
ll rf[N];
ll C(int n,int k){
    if (n<k || k<0) return 0;
    return (((f[n]*rf[k])%mod)*rf[n-k])%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    f[0]=1ll;
    for (ll i=1;i<=n;++i){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[n]=binpow(f[n],mod-2);
    for (ll i=n;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    ll res=0ll;
    for (int x=1;x<=n;x++){
        res+=C(n/x-1,k-1);
        res%=mod;
    }
    cout<<res<<endl;

    return 0;
}
/*
4
0100
1110
0101
0111
*/