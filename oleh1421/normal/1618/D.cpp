#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1000100;
int a[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll res=0ll;
    for (int i=1;i<=n-k-k;i++) res+=a[i];
    int mx=0;
    int cnt=(k>0);
    for (int i=n-k-k+2;i<=n;i++){
        if (a[i]!=a[i-1]){
            mx=max(mx,cnt);
            cnt=1;
        } else cnt++;
    }
    mx=max(mx,cnt);
    res+=max(0,mx-k);
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
/**
10 30 15
12 31 14 18

10 12 14 15 18 30 31
**/