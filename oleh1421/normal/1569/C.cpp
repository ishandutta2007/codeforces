#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=500010;
const ll mod=998244353;
int a[N];
ll f[N];
void solve(){
    int n;cin>>n;
    int mx=0;
    for (int i=1;i<=n;++i) cin>>a[i],mx=max(mx,a[i]);
    int cnt_mx=0;
    for (int i=1;i<=n;i++){
        cnt_mx+=(a[i]==mx);
    }
    f[0]=1ll;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    if (cnt_mx>1){
        cout<<f[n]<<endl;
        return;
    }
    int cnt0=0;
    for (int i=1;i<=n;i++){
        if (a[i]<=mx-2) cnt0++;
    }
    ll res=f[n-1];
    ll cur=1;
    for (ll i=cnt0;i>=1;i--){
        cur*=i;
        cur%=mod;
        res+=f[n-cnt0+i-2]*cur;
        res%=mod;
    }
    res=(f[n]+mod-res);
    cout<<res%mod<<endl;

}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}