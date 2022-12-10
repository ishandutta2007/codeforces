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

const LL maxk = 1e12 + 100,
	  maxn = 100 + 10;
LL dp[maxn][maxn],
   cnt[maxn];
LL n, k;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k
		>> s;
	bool found[26] = {0};
	for (int j = 0; j < n; j++) {
		if (!found[s[j] - 'a'])
			dp[1][j] = 1;
		found[s[j] - 'a'] = true;
	}
	for (int i = 2; i <= n; i++)
		for (int j = i - 1; j < n; j++)
			for (int k = j - 1; k >= 0 and (k + 1 == j or s[k + 1] != s[j]); k--) {
				dp[i][j] += dp[i - 1][k];
				smin(dp[i][j], maxk);
			}
	
	cnt[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < n; j++)
			cnt[i] += dp[i][j];
	LL ans = 0;
	for (int i = n; i >= 0; i--) {
		ans += min(k, cnt[i]) * (n - i);
		k -= min(k, cnt[i]);
	}
	if (k)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}