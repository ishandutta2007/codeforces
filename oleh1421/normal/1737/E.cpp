#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const int N=1000100;
const ll mod=1000000007;
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2);
}
ll p[N];
ll suf[N];
void solve(){
    int n;cin>>n;
    if (n==1){
        cout<<1<<endl;
        return;
    }
    p[1]=1;
    for (int i=2;i<=n;i++){
        p[i]=binpow(binpow(2,(i+1)/2),mod-2);
    }
    p[n]*=2ll;
    p[n]%=mod;
    ll sum=p[n];
    suf[n]=p[n];
    for (int i=n-1;i>=n/2+1;i--){
        suf[i]=(suf[i+1]+p[i])%mod;
    }
    for (int i=n/2;i>=1;i--){
        ll sum=suf[i*2];
        sum%=mod;
        p[i]*=(mod+1-sum);
        p[i]%=mod;
        suf[i]=(suf[i+1]+p[i])%mod;
    }
    for (int i=1;i<=n;i++) cout<<p[i]<<'\n';



}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}

/**


**/