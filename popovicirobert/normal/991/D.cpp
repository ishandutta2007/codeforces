#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string str[3];

int dp[101][2][2];

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> str[1];
    cin >> str[2];
    int n = str[1].size();
    str[1] = " " + str[1];
    str[2] = " " + str[2];
    /*for(i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            dp[1][i][j] = -n;
        }
    }*/
    //dp[1][0][0] = 0;
    for(i = 2; i <= n; i++) {
        if(str[1][i - 1] == '0' && str[1][i] == '0' && str[2][i - 1] == '0') {
            dp[i][1][0] = dp[i - 1][0][0] + 1;
        }
        if(str[1][i - 1] == '0' && str[1][i] == '0' && str[2][i] == '0') {
            dp[i][1][1] = max(dp[i - 1][0][1], dp[i - 1][0][0]) + 1;
        }
        if(str[1][i] == '0' && str[2][i] == '0' && str[2][i - 1] == '0') {
            dp[i][1][1] = max(dp[i][1][1], max(dp[i - 1][1][0], dp[i - 1][0][0]) + 1);
        }
        if(str[1][i - 1] == '0' && str[2][i - 1] == '0' && str[2][i] == '0') {
            dp[i][0][1] = dp[i - 1][0][0] + 1;
        }
        int mx = 0;
        for(int a = 0; a < 2; a++) {
            for(int b = 0; b < 2; b++) {
                mx = max(mx, dp[i - 1][a][b]);
                //printf("%d " ,dp[i][a][b]);
            }
        }
        for(int a = 0; a < 2; a++) {
            for(int b = 0; b < 2; b++) {
                dp[i][a][b] = max(dp[i][a][b] ,mx);
            }
        }
        //printf("\n");
    }
    int ans = 0;
    for(i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            ans = max(ans, dp[n][i][j]);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}