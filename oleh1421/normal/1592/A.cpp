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
const int N=500010;
const ll mod=998244353;
const ll inf=2000000000000000000;
int a[N];
void solve(){
    int n,H;cin>>n>>H;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll cur=H/(a[n-1]+a[n]);
    H-=cur*(a[n-1]+a[n]);
    cur*=2ll;
    if (H>0){
        cur++;
        H-=a[n];
        if (H>0) cur++;
    }
    cout<<cur<<endl;



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