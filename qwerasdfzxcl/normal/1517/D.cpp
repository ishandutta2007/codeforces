#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
bool chk[505][505];
ll edge[505][505][4];
ll dp[505][505][21];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main(){
    int n, m, K;
    scanf("%d %d %d", &n, &m, &K);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) chk[i][j] = 1;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<m;j++){
            int tmp;
            scanf("%d", &tmp);
            edge[i][j][2] = tmp;
            edge[i][j+1][3] = tmp;
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<=m;j++){
            int tmp;
            scanf("%d", &tmp);
            edge[i][j][0] = tmp;
            edge[i+1][j][1] = tmp;
        }
    }
    if (K&1){
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++) printf("-1 ");
            printf("\n");
        }
        return 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int k=0;k<21;k++) dp[i][j][k] = 1e18;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int k=0;k<4;k++){
                int nx = i+dx[k], ny = j+dy[k];
                if (!chk[nx][ny]) continue;
                dp[i][j][2] = min(dp[i][j][2], edge[i][j][k]*2);
            }
        }
    }
    for (int z=4;z<=K;z+=2){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                for (int k=0;k<4;k++){
                    int nx = i+dx[k], ny = j+dy[k];
                    if (!chk[nx][ny]) continue;
                    dp[i][j][z] = min(dp[i][j][z], edge[i][j][k]*2+dp[nx][ny][z-2]);
                }
            }
        }
    }
    /*printf("\n");
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            printf("%d %d: ", i, j);
            for (int k=0;k<4;k++) printf("%lld ", edge[i][j][k]);
            printf("\n");
        }
    }*/
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) printf("%lld ", dp[i][j][K]);
        printf("\n");
    }
    return 0;
}