#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
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
    ll n,m;cin>>n>>m;
    cout<<binpow(binpow(2ll,m)-1ll,n*1ll);
    return 0;
}