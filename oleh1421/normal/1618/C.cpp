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
ll a[N];
ll g[2];
void solve(){
    int n,k;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    g[0]=g[1]=0;
    for (int i=1;i<=n;i++){
        g[i%2]=__gcd(g[i%2],a[i]);
    }
    for (int rem=0;rem<2;rem++){
        bool ok=true;
        for (int i=2;i<=n;i++){
            if ((a[i]%g[rem]==0)==(a[i-1]%g[rem]==0)) ok=false;
        }
        if (ok){
            cout<<g[rem]<<endl;
            return;
        }
    }
    cout<<0<<endl;
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