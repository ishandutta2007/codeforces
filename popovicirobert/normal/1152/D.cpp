#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = 1005;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

pair <int, int> dp[2 * MAXN + 1][MAXN + 1];


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(i = 0; i <= 2 * n; i++) {
        for(j = 0; j <= n; j++) {
            dp[i][j].first = -1;
        }
    }

    dp[2 * n][0] = {0, 0};

    for(i = 2 * n - 1; i >= 1; i--) {

        for(j = 0; j <= n; j++) {

            bool good = 1;

            if(j > 0 && dp[i + 1][j - 1].first > -1) {

                if(dp[i][j].first == -1) {
                    dp[i][j].first = 0;
                }

                good &= dp[i + 1][j - 1].second;
                add(dp[i][j].first, dp[i + 1][j - 1].first);

            }

            if(j < n && dp[i + 1][j + 1].first > -1) {

                if(dp[i][j].first == -1) {
                    dp[i][j].first = 0;
                }

                good &= dp[i + 1][j + 1].second;
                add(dp[i][j].first, dp[i + 1][j + 1].first);

            }

            if(good == 0) {
                add(dp[i][j].first, 1);
                dp[i][j].second = 1;
            }

        }

    }

    cout << dp[1][1].first;

    //cin.close();
    //cout.close();
    return 0;
}