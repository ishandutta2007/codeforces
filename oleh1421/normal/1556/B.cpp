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
int a[N];
void solve(){
    int n;cin>>n;
    int cnt0=0,cnt1=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]%=2;
        if (a[i]) cnt1++;
        else cnt0++;
    }
    if (abs(cnt0-cnt1)>1){
        cout<<-1<<endl;
        return;
    }
    if (cnt0==cnt1){
        ll val0=0;
        int cn0=0,cn1=0;
        for (int i=1;i<=n;i++){
            if (a[i]){
                cn1++;
                val0+=max(0,cn0-cn1);
            } else {
                val0+=max(0,cn1-cn0);
                cn0++;
            }
        }
        cn0=cn1=0;
        ll val1=0;
        for (int i=1;i<=n;i++){
            if (a[i]){
                val1+=max(0,cn0-cn1);
                cn1++;
            } else {
                cn0++;
                val1+=max(0,cn1-cn0);
            }
        }
        cout<<min(val0,val1)<<endl;
        return;
    }
    if (cnt0>cnt1){
        ll val0=0;
        int cn0=0,cn1=0;
        for (int i=1;i<=n;i++){
            if (a[i]){
                cn1++;
                val0+=max(0,cn0-cn1);
            } else {
                val0+=max(0,cn1-cn0);
                cn0++;
            }
        }
        cout<<val0<<endl;
    } else {
        int cn0=0,cn1=0;
        ll val1=0;
        for (int i=1;i<=n;i++){
            if (a[i]){
                val1+=max(0,cn0-cn1);
                cn1++;
            } else {
                cn0++;
                val1+=max(0,cn1-cn0);
            }
        }
        cout<<val1<<endl;
    }


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