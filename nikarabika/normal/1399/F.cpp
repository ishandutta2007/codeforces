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

const int maxn = 3000 + 10;
const int INF = 1000 * 1000;
int dp[maxn][maxn];
pii seg[maxn];

bool segcmp(pii x, pii y) {
    if (x.L != y.L)
        return x.L < y.L;
    return x.R > y.R;
}

int solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seg[i].L >> seg[i].R;
    sort(seg, seg + n, segcmp);
    fill(dp[n], dp[n] + n + 1, INF);
    dp[n][0] = 0;
    for (int i = n - 1; i >= 0; i--) {
        int t = upper_bound(dp[i + 1], dp[i + 1] + n + 1, seg[i].R)
            - dp[i + 1] - 1;
        int k = upper_bound(seg, seg + n, MP(seg[i].R, INF)) - seg;
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j > t)
                smin(dp[i][j], max(seg[i].R, dp[k][j - t - 1]));
        }
    }
    cout << lower_bound(dp[0], dp[0] + n + 1, INF) - dp[0] - 1 << '\n';
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