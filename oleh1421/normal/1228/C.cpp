//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
const long long mod=1000000007ll;
ll binpow(ll a,ll b){
   if (b==0) return 1ll;
   if (b%2ll) return (a*binpow(a,b-1ll))%mod;
   else return binpow((a*a)%mod,b/2ll);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x,n;cin>>x>>n;
    ll res=1ll;
    vector<ll>v;
    ll d=2;
    while (d*d<=x && x>1){
        if (x%d==0){
            v.push_back(d);
            while (x%d==0) x/=d;
        }
        d++;
    }
    if (x>1) v.push_back(x);
    for (ll p:v){
        ll cur=1ll;
        ll cnt=0ll;
        while ((n/cur)>=p){
             cur*=p;
             res*=binpow(p,(n/cur));
        res%=mod;
             //cnt%=mod-1ll;
        }


    }
    cout<<res;
    return 0;
}
/*
8
0
2 0
0 4 0 1
0 0 0 0 0 5 0 0

*/