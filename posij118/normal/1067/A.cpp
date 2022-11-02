#include <bits/stdc++.h>
using namespace std;
long long M = 998244353;

int main(){
    int n;
    long long ans = 0;
    cin >> n;

    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
        a[i]--;
    }

    long long dp[2][200][3];
    long long p[2][201][3];

    for(int i = 0; i<2; i++){
        for(int j = 0; j<200; j++){
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
            dp[i][j][2] = 0;
        }
    }

    if(a[0] == -2){
        for(int i = 0; i<200; i++){
            dp[0][i][1] = 1;
            dp[0][i][0] = 0;
            dp[0][i][2] = 0;
        }
    }

    else{
        for(int i = 0; i<200; i++){
            dp[0][i][0] = 0;
            dp[0][i][1] = 0;
            dp[0][i][2] = 0;
            if(a[0] == i) dp[0][i][1] = 1;
        }
    }

    p[0][0][0] = 0;
    p[0][0][1] = 0;
    p[0][0][2] = 0;
    for(int i = 1; i<201; i++){
        p[0][i][0] = p[0][i - 1][0] + dp[0][i - 1][0];
        p[0][i][1] = p[0][i - 1][1] + dp[0][i - 1][1];
        p[0][i][2] = p[0][i - 1][2] + dp[0][i - 1][2];
    }

    for(int i = 1; i<n; i++){
        for(int j = 0; j<200; j++){
            dp[1][j][0] = 0;
            dp[1][j][1] = 0;
            dp[1][j][2] = 0;
            if(a[i] == j || a[i] == -2){

                dp[1][j][0] = p[0][200][0] - p[0][j + 1][0] + p[0][200][2] - p[0][j + 1][2];
                dp[1][j][0] %= M;
                dp[1][j][1] = p[0][j][0] + p[0][j][1] + p[0][j][2];
                dp[1][j][1] %= M;
                dp[1][j][2] = dp[0][j][0] + dp[0][j][1] + dp[0][j][2];
                dp[1][j][2] %= M;

            }
        }

        p[0][0][0] = 0;
        p[0][0][1] = 0;
        p[0][0][2] = 0;
        for(int j = 1; j<201; j++){
            p[0][j][0] = p[0][j - 1][0] + dp[1][j - 1][0];
            p[0][j][1] = p[0][j - 1][1] + dp[1][j - 1][1];
            p[0][j][2] = p[0][j - 1][2] + dp[1][j - 1][2];
        }

        for(int j = 0; j<200; j++){
            dp[0][j][0] = dp[1][j][0];
            dp[0][j][1] = dp[1][j][1];
            dp[0][j][2] = dp[1][j][2];
        }

    }

    for(int i = 0; i<200; i++){
        ans += dp[1][i][0] + dp[1][i][2];
        ans %= M;
    }

    cout << (ans + M) % M;

}