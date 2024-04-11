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

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 2048)
			i--, n--;
	}
	bool dp[n + 1][2050];
	memset(dp, 0, sizeof dp);
	dp[0][0] = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= 2048; j++) {
			dp[i + 1][j] |= dp[i][j];
			if (j + a[i] <= 2048)
				dp[i + 1][j + a[i]] |= dp[i][j];
		}
	if (dp[n][2048])
		cout << "YES\n";
	else
		cout << "NO\n";
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