#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=400010;
ll sum[1000001];
ll b[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i];
    ll res=0ll;
    for (int i=1;i<=n;i++){
        sum[b[i]-i+n]+=b[i];
        res=max(res,sum[b[i]-i+n]);
    }
    cout<<res;
    return 0;
}