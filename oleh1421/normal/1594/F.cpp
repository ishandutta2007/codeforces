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
#define endl '\n'
const int N=1000010;
const ll mod=1000000007;

void solve(){
    ll s,n,k;cin>>s>>n>>k;
    if (k>s){
        cout<<"NO\n";
        return;
    }
    if (s==k){
        cout<<"YES\n";
        return;
    }
    ll cnt=(s%k+1)*((1+s/k+1)/2)+(k-s%k-1)*((1+(s/k-1)+1)/2);
//    cout<<cnt<<endl;
    if (cnt>=n+1){
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
    }
//    4 2
//    0 1 4

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