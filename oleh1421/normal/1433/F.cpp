#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=75;
int dp[N][N*N];
int a[N][N];
int mx[N][N];
int Dp[N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
        for (int j=0;j<=m;j++){
            for (int t=0;t<=5000;t++){
                dp[j][t]=m+1;
            }
        }
        dp[0][0]=0;
        for (int j=0;j<m;j++){
            for (int t=0;t<=5000;t++){
                if (t+a[i][j+1]<=5000){
                    dp[j+1][t+a[i][j+1]]=min(dp[j+1][t+a[i][j+1]],dp[j][t]+1);
                }
                dp[j+1][t]=min(dp[j+1][t],dp[j][t]);
            }
        }
        for (int j=0;j<=k;j++) mx[i][j]=-1;
        for (int sum=0;sum<=5000;sum++){
            if (dp[m][sum]*2<=m) mx[i][sum%k]=sum;
        }
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            Dp[i][j]=-1;
        }
    }
    Dp[0][0]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<k;j++){
            if (Dp[i][j]==-1) continue;
//            cout<<i<<" "<<j<<" "<<Dp[i][j]<<endl;
            for (int t=0;t<k;t++){
                if (mx[i+1][t]==-1) continue;
                Dp[i+1][(j+t)%k]=max(Dp[i+1][(j+t)%k],Dp[i][j]+mx[i+1][t]);
            }
        }
    }
    cout<<Dp[n][0]<<endl;
    return 0;
}