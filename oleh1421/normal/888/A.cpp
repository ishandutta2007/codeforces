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
const int N=300010;
int a[N];
int32_t main()
{
//    freopen("landscape.in","r",stdin);
//    freopen("landscape.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int cnt=0;
    for (int i=2;i<n;i++){
        if (a[i]>max(a[i-1],a[i+1]) || a[i]<min(a[i-1],a[i+1])){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}