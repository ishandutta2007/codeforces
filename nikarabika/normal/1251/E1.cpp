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

const int maxn = 5e3 + 10;
const LL INF = 1e15;
LL dp[maxn][maxn];
pll a[maxn];
int cnt[maxn];
int n;

bool cmp(pii x, pii y) {
	return (x.L != y.L) ? x.L > y.L : x.R < y.R;
}

int solve() {
	memset(cnt, 0, sizeof cnt);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].L >> a[i].R;
		cnt[a[i].L]++;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i < maxn; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < maxn; j++)
			dp[i][j] = INF;
	for (int j = 0; j < maxn; j++)
		dp[n][j] = 0;
	for (int i = n; i > 0; i--)
		for (int j = 0; j <= n; j++) {
			if (j)
				smin(dp[i - 1][j - 1], dp[i][j] + a[i].R);
			if (a[i].L - cnt[a[i].L - 1] - j <= 0)
				smin(dp[i - 1][j], dp[i][j]);
		}
	cout << dp[0][0] << '\n';
//	for (int i = 0; i < n; i++)
//		cout << a[i + 1].L << ' ' << -a[i + 1].R << endl;
//	int x, y;
//	while (cin >> x >> y)
//		cout << dp[x][y] << endl;
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