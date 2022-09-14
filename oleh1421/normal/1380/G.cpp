//#pragma GCC optimize("trapv")
///SOLVE ACMP PROBLEM
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
typedef long long ll;
//#define int ll
using namespace std;
const int N=500010;
const ll mod=998244353ll;
int c[N];
ll pref[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (a*binpow(a,b-1))%mod;
    else return binpow((a*a)%mod,b/2ll);
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i];
    sort(c+1,c+n+1);
    reverse(c+1,c+n+1);
    ll dv=binpow(n,mod-2ll);
    pref[0]=0ll;
    for (int i=1;i<=n;i++){
        pref[i]=(pref[i-1]+c[i]*1ll);
    }
    for (int k=1;k<=n;k++){
        ll sum=0ll;
        int last=0;
        for (int i=1;i*k<=n;i++){
            last=i;
            ll cur=pref[i*k]-pref[(i-1)*k];
            sum+=cur*(i-1ll);
        }
        sum+=(pref[n]-pref[last*k])*(last+0ll);
        sum%=mod;
        sum*=dv;
        sum%=mod;
        cout<<sum<<" ";;
    }
    cout<<endl;

}
int32_t main()
{
//    freopen("cosmo.in","r",stdin);
//    freopen("cosmo.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}