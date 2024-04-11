#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=2000010;
const ll mod=998244353;
ll c[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i];
    ll res=0ll;
    for (int i=1;i<=n;i+=2){
        ll sum=0ll;
        ll mn=-1ll;
        for (int j=i+1;j<=n;j+=2){
            ll L=-mn;
            ll R=min(c[i],c[j]-sum);
            if (L<=R) res+=(R-L+1ll);
            sum-=c[j];
            mn=min(mn,sum);
            sum+=c[j+1];

        }
    }
    cout<<res<<endl;

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
/*
8
1 104
220 909
380 378
521 641
765 184
802 969
897 729
992 887
*/