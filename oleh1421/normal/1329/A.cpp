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
int l[N];
int p[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    ll sum=0ll;
    for (int i=1;i<=m;i++) cin>>l[i],sum+=l[i];
    if (sum<n){
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=m;i++){
        if (i+l[i]-1>n){
            cout<<-1;
            return 0;
        }
    }
    for (int i=1;i<=m;i++){

        cout<<max(i*1ll,n-sum+1)<<" ";
        sum-=l[i];

    }
    return 0;
}