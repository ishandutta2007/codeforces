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
void solve(){
    int a,b;cin>>a>>b;
    if ((a+b)%2){
        cout<<-1<<endl;
        return;
    }
    if (a==0  && b==0){
        cout<<0<<endl;
        return;
    }
    if (a==b){
        cout<<1<<endl;
        return;
    }
    cout<<2<<endl;



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