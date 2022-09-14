//#pragma GCC opitmize ("Ofast")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200050;
const ll mod=998244353ll;
ll pw[N];
void solve(){
    ll n;cin>>n;
    pw[0]=1ll;
    for (int i=1;i<=n;i++){
        pw[i]=(pw[i-1]*10ll)%mod;
    }
    for (ll i=1ll;i<n;i++){
        ll cur=(10ll*9ll*2ll*pw[n-i-1])%mod;
        if (n-i-1>0)cur+=((10ll*(n-i-1ll)*9ll*9ll)*pw[n-i-2])%mod;
        cur%=mod;
        cout<<cur<<" ";
    }
    cout<<"10\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}


/*
1
8889
3
333 998 1
*/