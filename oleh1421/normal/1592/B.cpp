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
int a[N],b[N];
void solve(){
    int n,x;cin>>n>>x;
    int g=__gcd(n,x);
    for (int i=0;i<n;i++) cin>>a[i],b[i]=a[i];
    sort(b,b+n);
    int L=n-x;
    int R=x-1;
    for (int i=L;i<=R;i++){
        if (a[i]!=b[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
 
 
 
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