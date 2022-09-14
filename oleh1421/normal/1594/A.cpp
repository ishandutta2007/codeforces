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
const ll mod=998244353;
const ll inf=2000000000000000000;
void solve(){
    ll n;cin>>n;
    ll cnt=0;
    while (n%2==0){
        n/=2ll;
        cnt++;
    }
//    m*2+2
//    x+1=2^cnt
//    2ll+2*x=2ll*2^cnt
    ll x=(1ll<<cnt)-1;
    cout<<n/2ll-x<<" "<<n/2ll+1ll+x<<endl;
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