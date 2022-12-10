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

const int maxn = 3e5 + 10;
int a[maxn],
	dp[maxn],
	pd[maxn],
	dpar[maxn],
	pdar[maxn],
	ans[maxn],
	n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a[n] = maxn;
	a[n + 1] = -1;
	fill(dp, dp + n, n + 1);
	fill(pd, pd + n, n + 0);
	dp[0] = n;
	dpar[0] = -1;
	pd[0] = n + 1;
	pdar[0] = -1;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) {
			dp[i] = dp[i - 1];
			dpar[i] = i - 1;
		}
		if (a[i] > a[pd[i - 1]] and a[i - 1] > a[dp[i]]) {
			dp[i] = i - 1;
			dpar[i] = pd[i - 1];
		}

		if (a[i] < a[i - 1]) {
			pd[i] = pd[i - 1];
			pdar[i] = i - 1;
		}
		if (a[i] < a[dp[i - 1]] and a[i - 1] < a[pd[i]]) {
			pd[i] = i - 1;
			pdar[i] = dp[i - 1];
		}
	}
	if (dp[n - 1] == n + 1 and pd[n - 1] == n)
		return cout << "NO\n", 0;
	if (dp[n - 1] != n + 1) {
		fill(ans, ans + n, 1);
		int id = n - 1;
		while (~id and id < n)
			ans[id] = 0, id = dpar[id];
	}
	else {
		int id = n - 1;
		while (~id and id < n)
			ans[id] = 1, id = pdar[id];
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}