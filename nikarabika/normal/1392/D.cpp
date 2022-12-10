//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

#define is_r(c) (c == 'R')

int solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dp[n + 1][4];
    int ans = n;
    for (int init = 0; init < 4; init++) {
        memset(dp, 63, sizeof dp);
        dp[0][init] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 4; j++) {
                for (int prej = j >> 1; prej < 4; prej += 2) {
                    int mask3 = (prej << 1) | j;
                    if (mask3 == 0 or mask3 == 7)
                        continue;
                    int cost = (j & 1) != is_r(s[i - 1]);
                    smin(dp[i][j], dp[i - 1][prej] + cost);
                }
            }
        }
        int x, y;
        smin(ans, dp[n][init]);
    }
    cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}