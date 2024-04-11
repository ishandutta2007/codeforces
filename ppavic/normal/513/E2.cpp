#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 3e4 + 100;
const int K = 205;
const int INF = 0x3f3f3f3f;
const int kof[4] = {-2, 0, 0, 2};

int dp[N][K][4], dp2[N][K][4], a[N],n,k;


int dinamika(){
    int sm = 0;
    dp[0][1][0] = -a[0];
    dp[0][1][1] = -a[0];
    dp[0][1][2] = a[0];
    dp[0][1][3] = a[0];
    dp2[0][1][0] = -a[0];
    dp2[0][1][1] = -a[0];
    dp2[0][1][2] = a[0];
    dp2[0][1][3] = a[0];
    for(int i = 1;i<n;i++){
        dp[i][1][0] = max(-a[i] + dp[i - 1][1][0], -a[i]);
        dp[i][1][1] = max(-a[i] + dp[i - 1][1][1], -a[i]);
        dp[i][1][2] = max(a[i] + dp[i - 1][1][2], a[i]);
        dp[i][1][3] = max(a[i] + dp[i - 1][1][3], a[i]);
        dp2[i][1][0] = max(dp[i][1][0], dp2[i - 1][1][0]);
        dp2[i][1][1] = max(dp[i][1][1], dp2[i - 1][1][1]);
        dp2[i][1][2] = max(dp[i][1][2], dp2[i - 1][1][2]);
        dp2[i][1][3] = max(dp[i][1][3], dp2[i - 1][1][3]);
    }
    for(int j = 2;j<=k;j++){
        dp[0][j][0] = -INF;
        dp[0][j][1] = -INF;
        dp[0][j][2] = -INF;
        dp[0][j][3] = -INF;
        dp2[0][j][0] = -INF;
        dp2[0][j][1] = -INF;
        dp2[0][j][2] = -INF;
        dp2[0][j][3] = -INF;
        if(j == k) break;
        for(int i = 1;i<n;i++){
            for(int msk = 0;msk<4;msk++){
                dp[i][j][msk] = -INF;
                dp[i][j][msk] = max(dp[i - 1][j][msk] + a[i] * kof[msk], dp[i][j][msk]);
                if(msk&1){
                    dp[i][j][msk] = max(dp2[i - 1][j - 1][0] + a[i] * kof[msk], dp[i][j][msk]);
                    dp[i][j][msk] = max(dp2[i - 1][j - 1][1] + a[i] * kof[msk], dp[i][j][msk]);
                }
                else{
                    dp[i][j][msk] = max(dp2[i - 1][j - 1][2] + a[i] * kof[msk], dp[i][j][msk]);
                    dp[i][j][msk] = max(dp2[i - 1][j - 1][3] + a[i] * kof[msk], dp[i][j][msk]);
                }
                dp2[i][j][msk] = max(dp[i][j][msk], dp2[i - 1][j][msk]);
            }
        }
    }
    for(int i = 1;i<n;i++){
        dp[i][k][0] = -INF;
        dp[i][k][1] = -INF;
        dp[i][k][0] = max(dp[i - 1][k][0] - a[i], dp[i][k][0]);
        dp[i][k][1] = max(dp[i - 1][k][1] + a[i], dp[i][k][1]);
        dp[i][k][0] = max(max(dp2[i - 1][k - 1][2], dp2[i - 1][k - 1][3]) - a[i], dp[i][k][0]);
        dp[i][k][1] = max(max(dp2[i - 1][k - 1][0], dp2[i - 1][k - 1][1]) + a[i], dp[i][k][1]);
        dp2[i][k][0] = max(dp[i][k][0], dp2[i - 1][k][0]);
        dp2[i][k][1] = max(dp[i][k][1], dp2[i - 1][k][1]);
    }
    return max(dp2[n - 1][k][0], dp2[n - 1][k][1]);
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++){
        scanf("%d", a + i);
    }
    printf("%d\n", dinamika());
}