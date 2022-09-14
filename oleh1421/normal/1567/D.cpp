#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=500010;
const int T_SZ=3000010;
const ll mod=1000000007;
ll ans[N];
void solve(){
    ll S,n;cin>>S>>n;

    for (int i=1;i<=n;i++) ans[i]=0;
    ll pw=1e9;
    ll z=n;
    for (int i=9;i>=1;i--){
//        x*pw+max(0,z-x)<=S
        ll x=min(n,S/pw);
//        x*pw+(z-x)
        x=min(x,(S-z)/(pw-1ll));
        ll r=max(x,z);
//        if (x==z){
//            cout<<i<<" "<<S<<endl;
//        }
        z=max(0ll,z-x);
        ll have=(S-z);

        for (ll j=0;j<x;j++){
            ll cur=min(9ll,(have-(x-j-1ll)*pw)/pw);
            ans[r-j]+=cur*pw;
            S-=cur*pw;
            have-=cur*pw;
        }
        pw/=10;
    }
//    cout<<z<<endl;
    for (int i=1;i<=z;i++){
        S--;
        ans[i]++;
    }
    for (int i=n;i>=1;i--){
        int cur=min(S,9-ans[i]%10);
        S-=cur;
        ans[i]+=cur;
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    ///max sum of digits + S

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

//0 2
//-1 3
//1 3
//0 4
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

C - centroid

5
0 0 -1 -1 1
*/