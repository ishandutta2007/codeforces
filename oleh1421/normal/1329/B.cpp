//#pragma GCC opitmize ("trapv")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=500010;
void solve(){
    ll d,m;cin>>d>>m;
    ll res=1ll;
    for (ll i=0;i<=30;i++){
        ll l=(1ll<<i);
        ll r=(2ll<<i)-1ll;
        if (l>d) break;
        r=min(r,d);
        res*=(r-l+2ll);
        res%=m;
    }
    res+=m-1;
    res%=m;
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