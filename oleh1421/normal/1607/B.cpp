#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
ll f(ll n){
    if (n==0) return 0;
    ll k=(n-1)/4;
    ll res=1ll+4ll*k;
    ll cur=-1;
    for (ll i=4ll*k+2;i<=n;i++){
        res+=cur*i;
        if (i%2) cur=-cur;
    }
    return res;
}
void solve(){
//    cout<<f(n)<<endl;
    ll x,n;cin>>x>>n;
    if (x%2){
        cout<<f(n)+x<<endl;
    } else {
        cout<<x-f(n)<<endl;
    }


}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
2 2
1 3
4 2
**/