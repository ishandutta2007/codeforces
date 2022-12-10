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
	LL a[n],
	b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	LL dp[n][3];
	memset(dp, 63, sizeof dp);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) if (!i or a[i] + j != a[i - 1] + k) {
				smin(dp[i][j], (i ? dp[i - 1][k] : 0LL) + j * b[i]);
			}
		}
	cout << *min_element(dp[n - 1], dp[n - 1] + 3) << '\n';
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