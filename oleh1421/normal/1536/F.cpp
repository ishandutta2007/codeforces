//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
const ll mod=1000000007;
ll f[N];
ll rf[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll C(int n,int k){
    if (k>n || k<0) return 0;
    return f[n]*rf[n-k]%mod*rf[k]%mod;
}
void solve(){
    int n;cin>>n;
    f[0]=1ll;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[n]=binpow(f[n],mod-2);
    for (ll i=n;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    ll res=0ll;
    for (int x=1;x<n;x+=2){
        res+=C(x+1,n-x-1)*f[x];
        res%=mod;
    }
    cout<<res*n*2ll%mod<<endl;

}
int32_t main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
//6*2!
///C=MEX(A)^B + MEX(B)^A
///MEX(C)=MEX(A)^MEX(B)
///A - DONE
/**
1 3
0.0 0.1 0.5 0.2
**/
//0 0 0