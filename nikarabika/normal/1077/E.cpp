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

const int maxn = 2e5 + 10,
	  maxl = 20;
int dp[maxl][maxn + maxn];
int a[maxn],
	b[maxn],
	cnt[maxn],
	n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	m = unique(b, b + n) - b;
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(b, b + m, a[i]) - b, cnt[a[i]]++;
	sort(cnt, cnt + m, greater<int>());
	for (int i = 0; i < m; i++) {
		for (int j = maxl - 1; j > 0; j--)
			for (int k = 1; k <= cnt[i]; k++)
				smax(dp[j][k], dp[j - 1][k << 1] + k);
	}
	int ans = 0;
	for (int i = 0; i < maxl; i++)
		for (int k = 0; k < maxn; k++)
			smax(ans, dp[i][k]);
	cout << ans << endl;
	return 0;
}