#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
ll d1,d2;
ll f(ll x,ll y){
    if (x==1) return (y/d1);
    else return (y/d2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,q;cin>>n>>m>>q;
    ll g=__gcd(n,m);
    d1=n/g;
    d2=m/g;
    while (q--){
        ll x,y,a,b;cin>>x>>y>>a>>b;
        y--;
        b--;
        if (f(x,y)==f(a,b)) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}