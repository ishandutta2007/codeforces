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

const int maxn = 100 + 10,
	  maxw = 100 * 100 + 10;
char dp[2][maxn][maxw];
int a[maxn],
	n;
map<char, char> cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], cnt[a[i]]++;
	sort(a, a + n);
	int cur = 0,
		nxt = 1;
	dp[cur][0][0] = 1;
	for (auto wei : cnt) {
		int w = wei.L,
			c = wei.R;
		memset(dp[nxt], 0, sizeof dp[nxt]);
		for (int j = 0; j < maxn; j++) {
			for (int k = 0; k < maxw; k++) if (dp[cur][j][k]) {
				for (int curc = 0; curc <= c and j + curc < maxn and k + curc * w < maxw; curc++) {
					char &ndp = dp[nxt][j + curc][k + curc * w];
					ndp += dp[cur][j][k];
					if (ndp > 1)
						ndp = 2;
				}
			}
		}
		swap(cur, nxt);
	}
	if (sz(cnt) == 1)
		return cout << n << endl, 0;
	if (sz(cnt) == 2) {
		auto tmp = *cnt.begin();
		if (dp[cur][tmp.R][tmp.L * tmp.R] == 1)
			return cout << n << endl, 0;
	}
	int ans = 0;
	for (auto tmp : cnt)
		for (int i = 1; i <= tmp.R; i++)
			if (dp[cur][i][i * tmp.L] == 1)
				smax(ans, i);
	cout << ans << endl;
	return 0;
}