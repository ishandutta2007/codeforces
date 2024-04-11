//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000001;
const ll mod=1000000007;
const int N=3000010;
ll f[N],rf[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll C(int n,int k){
    if (k<0 || n<k) return 0;
    return f[n]*rf[k]%mod*rf[n-k]%mod;
}
ll a[N];
ll b[4];
ll ans[N];
void solve(){
    int n,q;cin>>n>>q;
    f[0]=1ll;
    for (ll i=1;i<N;i++) f[i]=(f[i-1]*i)%mod;
    rf[N-1]=binpow(f[N-1],mod-2);
    for (ll i=N-1;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    for (int i=0;i<=n*3+3;i++) a[i]=C(n*3+3,i);
    a[0]+=mod-1;
    for (int i=0;i<=3;i++) b[i]=C(3,i);
    b[0]+=mod-1;
    for (int i=3*n;i>=0;i--){
        ans[i]=a[i+3];
        for (int j=0;j<=3;j++){
            a[i+j]+=mod-ans[i]*b[j]%mod;
            a[i+j]%=mod;
        }
    }
    for (int i=1;i<=q;i++){
        int x;cin>>x;
        cout<<ans[x]<<endl;
    }

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}