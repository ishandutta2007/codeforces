#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=764983111ll;
const long long mod2=764983113ll;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;cin>>n;
    vector<ll>d;
    for (ll i=2ll;i*i<=n;i++){
        if (n%i) continue;
        d.push_back(i);
        if (i*i<n) d.push_back(n/i);
    }
    for (ll x:d) n=__gcd(n,x);
    cout<<n;
    return 0;
}