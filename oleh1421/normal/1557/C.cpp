//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define double long double
using namespace std;
const int N=1000010;
const ll mod=1000000007;
ll pw[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
void solve(){
    ll n,k;cin>>n>>k;
    if (n%2){
        ll res=1ll;
        for (int i=0;i<k;i++){
            res*=(pw[n-1]+1ll);
            res%=mod;
        }
        cout<<res<<endl;
        return;
    }
    ll res=0ll;
    ll mult=1ll;
    for (int i=k-1;i>=0;i--){
        res+=mult*binpow(pw[n],i);
        res%=mod;
        mult*=pw[n-1]-1ll;
        mult%=mod;
    }
    res+=mult;
    cout<<res%mod<<endl;

}

int32_t main()
{
    pw[0]=1;
    for (int i=1;i<N;i++){
        pw[i]=(pw[i-1]*2ll)%mod;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}