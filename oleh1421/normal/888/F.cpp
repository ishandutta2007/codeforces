//#pragma GCC opitmize ("trapv")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=510;
const ll mod=1000000007ll;
int a[N][N];
ll dp[N][N][2];
int32_t main()
{
//    freopen("landscape.in","r",stdin);
//    freopen("landscape.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        dp[i][i][0]=1ll;
    }
    for (int len=2;len<=n;len++){
        for (int l=1;l<=n;l++){
            int r=l+len-1;
            if (r>n) r-=n;
            for (int i=l;i!=r;i=(i<n ? i+1 : 1)){
                int nxt=(i<n ? i+1 : 1);
                if (a[l][r]){
                    dp[l][r][1]+=(dp[l][i][0]+dp[l][i][1])*(dp[nxt][r][0]+dp[nxt][r][1]);
                    dp[l][r][1]%=mod;
                }
                if (a[l][i]){
                    dp[l][r][0]+=dp[l][i][1]*(dp[i][r][0]+dp[i][r][1]);
                    dp[l][r][0]%=mod;
                }
            }
        }
    }
    cout<<(dp[1][n][0]+dp[1][n][1])%mod;
    return 0;
}