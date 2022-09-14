//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=103;
int p[N];
int dp[N][N][N][2];
int cnt[2];
int f[2];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>p[i];
        if (p[i]) cnt[p[i]%2]++;
    }
    for (int x=0;x<=n;x++) for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) for (int t=0;t<2;t++) dp[x][i][j][t]=1000000001;
    f[1]=(n+1)/2-cnt[1];
    f[0]=n/2-cnt[0];
    if (p[1]) dp[1][0][0][p[1]%2]=0;
    else {
        dp[1][1][0][0]=0;
        dp[1][0][1][1]=0;
    }
    //cout<<f[0]<<" "<<f[1]<<endl;
    for (int i=1;i<n;i++){
        for (int x=0;x<=f[0];x++){
            for (int y=0;y<=f[1];y++){
                for (int t=0;t<2;t++){
                    //cout<<i<<" "<<x<<" "<<y<<" "<<t<<" "<<dp[i][x][y][t]<<endl;
                    if (p[i+1]) dp[i+1][x][y][p[i+1]%2]=min(dp[i+1][x][y][p[i+1]%2],dp[i][x][y][t]+(t^(p[i+1]%2)));
                    else {
                        if (x<f[0]) dp[i+1][x+1][y][0]=min(dp[i+1][x+1][y][0],dp[i][x][y][t]+t);
                        if (y<f[1]) dp[i+1][x][y+1][1]=min(dp[i+1][x][y+1][1],dp[i][x][y][t]+(t^1));
                    }
                }
            }
        }
    }
    cout<<min(dp[n][f[0]][f[1]][0],dp[n][f[0]][f[1]][1]);
    return 0;
}