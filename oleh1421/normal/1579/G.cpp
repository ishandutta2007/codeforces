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
int dp[2][3010];
void solve(){
    int n;cin>>n;
    for (int i=0;i<2;i++){
        for (int j=0;j<=2000;j++) dp[i][j]=2001;
    }
//    for (int i=1;i<=n;i++) cin>>a[i];
    dp[0][0]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<=2000;j++) dp[(i+1)%2][j]=2001;
        int x;cin>>x;
        for (int j=0;j<=2000;j++){
//            -j dp[i%2][j]
            dp[(i+1)%2][max(0,j-x)]=min(dp[(i+1)%2][max(0,j-x)],dp[i%2][j]+max(0,x-j));
            if (j+x<=2000) dp[(i+1)%2][j+x]=min(dp[(i+1)%2][j+x],max(dp[i%2][j],j+x));
        }
    }
    int ans=2001;
    for (int i=0;i<=2000;i++) ans=min(ans,dp[n%2][i]);
    cout<<ans<<endl;
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
1
4 9 2
*.*.*...*
.*.*...*.
..*.*.*..
.....*...
**/