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
const ll mod=1000000007ll;
ll f[10];
int32_t main()
{
//    freopen("landscape.in","r",stdin);
//    freopen("landscape.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    f[0]=1ll;
    f[1]=0ll;
    f[2]=1ll;
    f[3]=2ll;
    f[4]=9ll;
    ll sum=0ll;
    int n,kk;cin>>n>>kk;
    for (int k=0;k<=kk;k++){
        ll res=f[k];
        for (ll i=n-k+1ll;i<=n;i++){
            res*=i;
        }
        for (ll i=1ll;i<=k;i++){
            res/=i;
        }
        sum+=res;
    }
    cout<<sum;
    return 0;
}