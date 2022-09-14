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
ll dp[62];
void solve(){
    ll k;cin>>k;
    dp[1]=1;
    for (int i=2;i<=k;i++){
        dp[i]=dp[i-1]*dp[i-1]%mod*16ll%mod;
    }
    cout<<dp[k]*6ll%mod<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}