#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 505;

int n, k;
bool dp[505][505];

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    int su = 0, sv = 0;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        su += u;
        sv += v;
        if (u + v < k) {
            for (int j = 0; j < k; j++) dp[i][j] = dp[i - 1][j];
        } else {
            for (int j = 0; j < k; j++) dp[i][j] = dp[i - 1][j];
            int t = min(u, k - 1);
            for (int j = 1; j <= t; j++) {
                int tt = k - j;
                if (tt > v) continue;
                // (j, t);
                for (int jj = 0; jj < k; jj++) {
                    if (dp[i - 1][jj]) {
                        dp[i][(jj + j) % k] = 1;
                    }
                }
            }
        }
    }
    long long ans = su / k + sv / k;
    int a = su % k;
    int b = sv % k;
    for (int i = 1; i <= a; i++) {
        int t = k - i;
        if (t <= b && dp[n][i]) {
            ans++;
            break;
        }
    }
    cout << ans;
    return 0;
}