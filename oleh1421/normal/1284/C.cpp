//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=300001;
ll f[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;cin>>n>>m;
    f[0]=1ll;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%m;
    }
    ll res=0ll;
    for (ll i=1;i<=n;i++){
        res+=((((n-i+1ll)*(n-i+1ll))%m*f[i])%m*f[n-i])%m;
        res%=m;
    }
    cout<<res;
    return 0;
}