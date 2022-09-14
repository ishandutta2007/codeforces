#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=210;
const ll mod=1000000007ll;
int dp[N][N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,K;cin>>n>>K;
    string S,T;cin>>S>>T;
    if (T[0]==T[1]){
        int cnt=0;
        for (auto x:S){
            cnt+=(x==T[0]);
        }
        cnt+=K;
        cnt=min(cnt,n);
        cout<<cnt*(cnt-1)/2<<endl;
        return 0;
    }
    for (int j=0;j<=n;j++){
        for (int t=0;t<=n;t++){
            for (int k=0;k<=n;k++){
                dp[j][t][k]=-1000000001;
            }
        }
    }
    dp[0][0][0]=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=i;j++){
            for (int t=0;t<=i;t++){
                if (S[i-1]==T[0]){
                    if (j){
                        dp[i][j][t]=max(dp[i][j][t],dp[i-1][j-1][t]);
                    }
                    if (t){
                        dp[i][j][t]=max(dp[i][j][t],dp[i-1][j][t-1]+j);
                    }

                } else if (S[i-1]==T[1]){
                    dp[i][j][t]=max(dp[i][j][t],dp[i-1][j][t]+j);
                    if (j && t){
                        dp[i][j][t]=max(dp[i][j][t],dp[i-1][j-1][t-1]);
                    }
                } else {
                    dp[i][j][t]=dp[i-1][j][t];
                    if (j && t){
                        dp[i][j][t]=max(dp[i][j][t],dp[i-1][j-1][t-1]);
                    }
                    if (t){
                        dp[i][j][t]=max(dp[i][j][t],dp[i-1][j][t-1]+j);
                    }
                }
            }
        }
    }
    int res=0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=K;j++){
            res=max(res,dp[n][i][j]);
        }
    }
    cout<<res<<endl;
    return 0;
}