#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=200010;
const ll mod=1000000007;
ll cnt[N];
ll f[N];
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll inv(ll x){
    return binpow(x,mod-2);
}
ll C(int n,int k){
    if (n<k || k<0) return 0;
    return f[n]*inv(f[k])%mod*inv(f[n-k])%mod;
}
void solve(){
    int n,k;cin>>n>>k;
    f[0]=1ll;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    for (int i=0;i<=n;i++) cnt[i]=0;
    ll res=0ll;
    cnt[0]=1;
    for (int i=1;i<=n && (i-1)*k<=n;i++){
        cnt[i]=0;
//        C(i-1,i-1)+...+C((i-1)+n-(i-1)*k-1,i-1)
//
//        for (int j=1;j<=n-(i-1)*k;j++){
////            n-j-(i-1)*k>=0
////            j<=n-(i-1)*k
//            cnt[i]+=C((i-1)+n-j-(i-1)*k,i-1);
//            cnt[i]%=mod;
//        }
        cnt[i]=C(i-1+n-(i-1)*k,i);
    }
    for (int i=0;i<=n;i++){
        res+=cnt[i]*inv(C(n,i));
        res%=mod;
    }
    cout<<res<<endl;

}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//x+y x-y
//
//
//x+y -2*y
//
//x-y

//x y
//x x-y
//x x-2*y