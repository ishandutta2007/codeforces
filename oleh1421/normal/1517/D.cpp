#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=510;
const ll mod=1000000007;
const int inf=1000000001;
int R[N][N];
int L[N][N];
int D[N][N];
int U[N][N];
int dp[12][N][N];
int ans[N][N];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=m+1;j++){
            L[i][j]=R[i][j]=D[i][j]=U[i][j]=inf;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<m;j++){
            int x;cin>>x;
            R[i][j]=L[i][j+1]=x;
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<=m;j++){
            int x;cin>>x;
            D[i][j]=U[i+1][j]=x;
        }
    }
    if (k%2){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cout<<-1<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for (int i=0;i<=10;i++){
        for (int j=0;j<=n+1;j++){
            for (int t=0;t<=m+1;t++){
                dp[i][j][t]=inf;
            }
        }
    }
    for (int x=1;x<=n;x++){
        for (int y=1;y<=m;y++){
            dp[0][x][y]=0;
            for (int d=1;d<=k/2;d++){
                for (int i=max(1,x-d);i<=min(n,x+d);i++){
                    for (int j=max(1,y-d+abs(x-i));j<=min(m,y+d-abs(x-i));j++){
                        dp[d][i][j]=min({dp[d-1][i-1][j]+U[i][j],dp[d-1][i+1][j]+D[i][j],dp[d-1][i][j-1]+L[i][j],dp[d-1][i][j+1]+R[i][j]});
                    }
                }
            }
            int d=k/2;
            ans[x][y]=inf;
            for (int i=max(1,x-d);i<=min(n,x+d);i++){
                for (int j=max(1,y-d+abs(i-x));j<=min(m,y+d-abs(i-x));j++){
                    ans[x][y]=min(ans[x][y],dp[d][i][j]*2);
                }
            }
            dp[0][x][y]=inf;
            for (int d=1;d<=k/2;d++){
                for (int i=max(1,x-d);i<=min(n,x+d);i++){
                    for (int j=max(1,y-d+abs(i-x));j<=min(m,y+d-abs(i-x));j++){
                        dp[d][i][j]=inf;
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }


}
int32_t main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5 9 7
...##....
..#.##..#
..#....##
.##...#..
....#....
W
**/

/**
3 2 3
3 3
2 2
1 1
**/