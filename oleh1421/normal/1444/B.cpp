#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const ll mod=998244353;
ll a[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (a*binpow(a,b-1))%mod;
    else return binpow((a*a)%mod,b/2ll);
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n*2;i++) cin>>a[i];
    sort(a+1,a+n*2+1);
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        sum+=a[n+i]-a[i];
    }
    sum%=mod;
    for (ll i=n+1;i<=n*2;i++){
        sum*=i;
        sum%=mod;
    }
    for (ll i=1;i<=n;i++){
        sum*=binpow(i,mod-2);
        sum%=mod;
    }
    cout<<sum<<endl;
}
int main()
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
1
4 0 4
1 2 2 3
*/