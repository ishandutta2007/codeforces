#include<bits/stdc++.h>
using namespace std;
int r, s, p;
double dp[111][111][111], Ansa, Ansb, Ansc;
int main() {
    scanf("%d%d%d", &r, &s, &p), dp[r][s][p] = 1.0;
    for(int i = r; i >= 0; i--) 
        for(int j = s; j >= 0; j--) 
            for(int k = p; k >= 0; k--) {
                if(i * j + j * k + k * i == 0) continue;
                int sum = i + j + k;
                double es = 1.0 * sum * (sum - 1) / (i * j + j * k + k * i);
                if(j != 0) dp[i][j - 1][k] += es * i / sum * j / (sum - 1) * dp[i][j][k];
                if(k != 0) dp[i][j][k - 1] += es * j / sum * k / (sum - 1) * dp[i][j][k];
                if(i != 0) dp[i - 1][j][k] += es * k / sum * i / (sum - 1) * dp[i][j][k];
            }
    for(int i = 1; i <= r; i++) Ansa += dp[i][0][0];
    for(int i = 1; i <= s; i++) Ansb += dp[0][i][0];
    for(int i = 1; i <= p; i++) Ansc += dp[0][0][i];
    printf("%.10lf %.10lf %.10lf\n", Ansa, Ansb, Ansc);
    return 0;
}