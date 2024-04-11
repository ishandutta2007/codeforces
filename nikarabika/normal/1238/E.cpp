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

const int maxm = 20;
int dp[1 << maxm],
	cnt[maxm][maxm],
	n, m;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m
		>> s;
	for (int i = 1; i < n; i++) {
		int c1 = s[i] - 'a';
		int c2 = s[i - 1] - 'a';
		cnt[c1][c2]++;
		cnt[c2][c1]++;
	}
	for (int mask = 1; mask < (1 << m); mask++) {
		int nval = 0;
		for (int i = 0; i < m; i++)
			if ((mask >> i) & 1)
				for (int j = 0; j < m; j++)
					if ((mask >> j) & 1 ^ 1)
						nval += cnt[i][j];
		dp[mask] = 1e9;
		for (int i = 0; i < m; i++)
			if ((mask >> i) & 1)
				smin(dp[mask], dp[mask ^ (1 << i)] + nval);
	}
	cout << dp[(1 << m) - 1] << endl;
	return 0;
}