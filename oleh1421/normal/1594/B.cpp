//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//#define int ll
//#define endl '\n'
const int N=1000010;
const ll mod=1000000007;
const ll inf=2000000000000000000;
void solve(){
    ll n,k;cin>>n>>k;
    ll cur=1ll;
    ll res=0ll;
    for (ll i=0;i<30;i++){
        if (k&(1ll<<i)) res=(res+cur)%mod;
        cur=(cur*n)%mod;
    }
    cout<<res<<endl;
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