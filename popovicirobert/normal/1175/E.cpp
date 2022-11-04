#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 5e5;

int dp[MAXN + 1][20];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for(i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        dp[l][0] = max(dp[l][0], r);
    }

    for(i = 1; i <= MAXN; i++) {
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);
    }

    for(int bit = 1; bit < 20; bit++) {
        dp[0][bit] = dp[dp[0][bit - 1]][bit - 1];
        for(i = 1; i <= MAXN; i++) {
            dp[i][bit] = max(dp[i - 1][bit], dp[dp[i][bit - 1]][bit - 1]);
        }
    }

    while(m--) {
        int x, y;
        cin >> x >> y;

        int r = x, ans = 0;

        for(int bit = 19; bit >= 0; bit--) {
            if(dp[r][bit] < y) {
                r = dp[r][bit];
                ans += (1 << bit);
            }
        }

        r = dp[r][0];
        ans++;

        if(r < y) {
            ans = -1;
        }

        cout << ans << "\n";
    }

    //cin.close();
    //cout.close();
    return 0;
}