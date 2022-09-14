//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
const ll mod=1000000007ll;
const int A=1000100;
ll h[N];
void solve(){
    ll n;cin>>n;
    ll sum=0ll;
    bool ok=true;
    for (ll i=1;i<=n;i++) {
        cin>>h[i];
        sum+=h[i];
        if (i*(i-1ll)/2ll>sum){
            ok=false;
        }
    }
    if (!ok) cout<<"NO\n";
    else cout<<"YES\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}