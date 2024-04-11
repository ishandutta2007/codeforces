//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//#define int ll
#define endl '\n'
const int N=1000010;
const ll mod=998244353;
const ll inf=2000000000000000000;
int a[N];
int L[N];
int calc(vector<int>v){
    int res=0;

    int xr=0;
    L[xr]=1;
    for (int i=0;i<v.size();i++){
        xr^=v[i];
        if (L[xr]) {
            res=max(res,i-L[xr]+2);
        }
        else L[xr]=i+2;
    }
    xr=0;
    L[xr]=0;
    for (int i=0;i<v.size();i++){
        xr^=v[i];
        L[xr]=0;
    }
//    if (res%2){
//        for (int i:v) cout<<i<<" ";
//        cout<<endl;
//    }
    return res;

}
void solve(){
    int n;cin>>n;
//    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=0;
    int ans=0;
    for (int bt=0;bt<20;bt++){
//        cout<<bt<<endl;
        vector<int>v;
        for (int i=1;i<=n+1;i++){
            if (a[i]&(1<<bt)) v.push_back(a[i]>>bt);
            else {
                ans=max(ans,calc(v));
                v.clear();
            }
        }
    }
    cout<<ans<<endl;
//    int ans1=0;
//    for (int l=1;l<=n;l++){
//        int aa=(1<<20)-1,xx=0;
//        for (int r=l;r<=n;r++){
//            aa&=a[r];
//            xx^=a[r];
//            if (aa>xx){
//                ans1=max(ans1,r-l+1);
//            }
//        }
//    }
//    cout<<ans1<<endl;
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