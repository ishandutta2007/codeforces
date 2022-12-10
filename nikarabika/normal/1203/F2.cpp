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
	  maxr = 1000 * 1000 + 10;
int dp[2][maxr];
int a[maxn],
	b[maxn],
	n, r;
vector<pii> vec[2];

void solve(vector<pii> &vec, int dp[], int st) {
	sort(all(vec));
	fill(dp, dp + maxr, (st == 0 ? 0 : -10000));
	dp[st] = 0;
	for (auto p : vec)
		for (int i = maxr - 1; i >= 0; --i)
			if (i >= p.L and i + p.R < maxr)
				smax(dp[i + p.R], (dp[i] + 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		int fi, se;
		cin >> fi >> se;
		if (se < 0) {
			if (fi >= se)
				vec[1].PB(MP(fi + se, -se));
		}
		else
			vec[0].PB(MP(fi, se));
	}
	solve(vec[0], dp[0], r);
	solve(vec[1], dp[1], 0);
	int ans = 0,
		curmx = 0;
	for (int i = 0; i < maxr; i++) {
		smax(curmx, dp[1][i]);
		smax(ans, curmx + dp[0][i]);
	}
	cout << ans << endl;
	return 0;
}