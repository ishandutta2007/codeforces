#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll mod=1000000007ll;
const int N=510;
int a[N];
int ans[N][N];
pair<bool,int>dp[N][N];
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) dp[i][j]={0,0};
    for (int i=1;i<=n;i++) dp[i][i]={1,a[i]},ans[i][i]=1;
    for (int len=2;len<=n;len++){
        for (int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            ans[l][r]=r-l+1;
            for (int i=l;i<r;i++){
                if (dp[l][i]==dp[i+1][r] && dp[l][i].first){
                    dp[l][r]={1,dp[l][i].second+1};
                    break;
                }
            }
            if (dp[l][r].first){
                ans[l][r]=1;
            } else {
                for (int i=l;i<r;i++) ans[l][r]=min(ans[l][r],ans[l][i]+ans[i+1][r]);
            }
        }
    }
    cout<<ans[1][n];
    return 0;
}