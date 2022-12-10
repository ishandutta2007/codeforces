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
	  maxm = 1000 * 1000 + 10;
int dp[maxm],
	last[maxn];
int par[maxm];
int dis[maxn][maxn];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(dis, 63, sizeof dis);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == '1')
				dis[i][j] = 1;
			if (i == j)
				dis[i][j] = 0;
		}
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				smin(dis[i][j], dis[i][k] + dis[k][j]);
	vector<int> p, ans;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x, x--;
		p.PB(x);
	}
	memset(dp, 63, sizeof dp);
	dp[0] = 1;
	fill(last, last + n, (int)-1e9);
	last[p[0]] = 0;
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++)
			if (dis[j][p[i]] == i - last[j] and dp[last[j]] + 1 < dp[i]) {
				smin(dp[i], dp[last[j]] + 1);
				par[i] = last[j];
			}
		last[p[i]] = i;
	}
	par[0] = -1;
	cout << dp[m - 1] << endl;
	int id = m - 1;
	while (~id) {
		ans.PB(p[id]);
		id = par[id];
	}
	reverse(all(ans));
	for (auto u : ans)
		cout << u + 1 << ' ';
	cout << endl;
	return 0;
}