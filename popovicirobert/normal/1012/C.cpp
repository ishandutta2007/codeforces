#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int INF = 1e12;
const int MAXN = 5005;

int h[MAXN + 1];

ll dp[MAXN + 1][MAXN / 2 + 1][2];

inline int get(int x, int y, int z) {
    return max(0, x - (y - 1)) + max(0, z - (y - 1));
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> h[i];
    }
    n++;
    dp[0][0][1] = dp[1][0][1] = INF;
    for(i = 1; i <= n / 2; i++) {
        for(j = 0; j < 2; j++) {
            dp[0][i][j] = INF;
            dp[1][i][j] = INF;
        }
    }
    for(i = 2; i <= n; i++) {
        dp[i][0][1] = INF;
        for(int j = 1; j <= n / 2; j++) {
            //dp[i][j][0] = dp[i][j][1] = INF;
            int val;
            if(i == 2) {
                val = 1;
            }
            else {
                val = h[i - 3];
            }
            ll cur = min(dp[i - 2][j - 1][0] + 1LL * get(h[i - 2], h[i - 1], h[i]), dp[i - 2][j - 1][1] + 1LL * get(min(h[i - 2], val - 1), h[i - 1], h[i]));
            dp[i][j][1] = cur;
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);
        //printf("%d %d %d\n" ,dp[i][j][0],dp[i][j][1],dp[i - 2][j - 1][1]);
        }
        //printf("\n\n");
    }
    for(i = 1; i <= n / 2; i++) {
        cout << min(dp[n][i][0], dp[n][i][1]) << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}