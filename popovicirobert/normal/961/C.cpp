#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string str[5][101];
int dp[5][2];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, t;
    ios::sync_with_stdio(false);
    cin >> n;
    for(t = 1; t <= 4; t++) {
        for(i = 1; i <= n; i++) {
            cin >> str[t][i];
            str[t][i] = " " + str[t][i];
        }
    }
    for(t = 1; t <= 4; t++) {
        for(int p = 0; p < 2; p++) {
            int cur = p;
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= n; j++) {
                    if(str[t][i][j] != cur + '0')
                        dp[t][p]++;
                    cur = 1 - cur;
                }
            }
        }
    }
    int sum = 0, ans = 1e9;
    for(i = 1; i <= 4; i++) {
        sum += dp[i][0];
    }
    for(i = 1; i <= 4; i++) {
        for(j = 1; j <= 4; j++) {
            if(i != j)
                ans = min(ans, sum + dp[i][1] - dp[i][0] + dp[j][1] - dp[j][0]);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}