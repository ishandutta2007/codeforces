//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=160000;
const ll mod=998244353;
ll f(ll k,ll x){
    if (x<=k) return (x+1ll)*x/2ll;
    x=2*k-1-x;
    return k*(k+1ll)/2ll+k*(k-1ll)/2ll-x*(x+1ll)/2ll;
}
void solve(){
    ll k,x;cin>>k>>x;
    if (k*(k+1)/2+k*(k-1)/2<=x){
        cout<<2*k-1<<endl;
        return;
    }
    ll ans=0ll;
    for (ll i=30;i>=0;i--){
        if (ans+(1ll<<i)<2*k-1 && f(k,ans+(1ll<<i))<x) ans+=(1ll<<i);
    }
    cout<<ans+1<<endl;
}
int32_t  main()
{
//    cin>>X>>Y;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

/**
11 3
1 2
2 3
3 4
4 5
5 6
6 7
4 8
8 9
9 10
10 11
**/