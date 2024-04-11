#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
//#define endl '\n'
const int N=2000010;
const ll mod=998244353;
int get_and(int i,int j){
    cout<<"and "<<i<<" "<<j<<endl;
    int ans;cin>>ans;
    return ans;
}
int get_or(int i,int j){
    cout<<"or "<<i<<" "<<j<<endl;
    int ans;cin>>ans;
    return ans;
}
int a[N];
void solve(){
    int n,k;cin>>n>>k;
    int x=get_and(1,2)+get_or(1,2);
    int y=get_and(1,3)+get_or(1,3);
    int z=get_and(2,3)+get_or(2,3);
    a[1]=(x+y-z)/2;
    a[2]=(x+z-y)/2;
    a[3]=(y+z-x)/2;
    for (int i=4;i<=n;i++){
        a[i]=get_and(1,i)+get_or(1,i)-a[1];
    }
    sort(a+1,a+n+1);
    cout<<"finish "<<a[k]<<endl;
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