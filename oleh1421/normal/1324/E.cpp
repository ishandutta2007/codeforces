#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=2010;
int dp[N][N];
int a[N];
int main()
{
//    freopen("three.in","r",stdin);
//    freopen("three.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,h,l,r;cin>>n>>h>>l>>r;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=n;i++){
        for (int j=0;j<=h;j++){
            dp[i][j]=-1000000001;
        }
    }
    dp[0][0]=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<h;j++){
            ///dp[i-1][j]
            int nxt1=(j+a[i]-1)%h;
            int nxt2=(j+a[i])%h;
            dp[i][nxt1]=max(dp[i][nxt1],dp[i-1][j]+(nxt1>=l && nxt1<=r));
            dp[i][nxt2]=max(dp[i][nxt2],dp[i-1][j]+(nxt2>=l && nxt2<=r));
        }
    }
    int maxx=0;
    for (int i=0;i<=h;i++) maxx=max(maxx,dp[n][i]);
    cout<<maxx;
    return 0;
}