#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int dp[101][101][2][2], a[101];

void solve(){
    int n;
    scanf("%d", &n);

    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for (int i=1;i<=n;i++){
        scanf("%d", a+i);
        if (a[i] < 0) a[i] = -a[i];
        cnt[a[i]&1]++;
    }

    if (dp[cnt[0]][cnt[1]][0][0]) printf("Alice\n");
    else printf("Bob\n");
}

int main(){
    dp[0][0][0][0] = 1;
    dp[0][0][1][1] = 1;
    for (int i=0;i<=100;i++){
        for (int j=0;j<=100;j++){
            for (int k=0;k<2;k++){
                if (i && !dp[i-1][j][k][1]) dp[i][j][k][0] = 1;
                if (j && !dp[i][j-1][k^1][1]) dp[i][j][k][0] = 1;

                if (i && !dp[i-1][j][k][0]) dp[i][j][k][1] = 1;
                if (j && !dp[i][j-1][k][0]) dp[i][j][k][1] = 1;
            }
        }
    }

    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}