#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 5e3;
const int MOD = (int) 1e9 + 7;

char v[MAXN + 1];

int dp[2][MAXN + 1];

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dp[1][1] = 1;
    for(i = 2; i <= n; i++) {
        memset(dp[i & 1], 0, sizeof(dp[i & 1]));
        if(v[i - 1] == 'f') {
            for(j = 1; j < n; j++)
                dp[i & 1][j + 1] = dp[1 - i & 1][j];
        }
        else {
            int s = 0;
            for(j = n; j >= 1; j--) {
                s += dp[1 - i & 1][j];
                mod(s);
                dp[i & 1][j] = s;
            }
        }
      /*  for(j = 1; j <= n; j++) {
            printf("%d " ,dp[i & 1][j]);
        }
        printf("\n"); */
    }
    int ans = 0;
    for(i = 1; i <= n; i++) {
        ans += dp[n & 1][i];
        mod(ans);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}