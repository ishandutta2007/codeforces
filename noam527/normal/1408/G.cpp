#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int N = 1505;

struct comp {
	vector<int> v;
	int cnt;
	comp() {}
	comp(int x) {
		v = { x };
		cnt = 0;
	}
};

int n;
int a[N][N];
pair<int, int> e[N * N / 2];

int dp[N][N];

void solve() {
	cin >> n;
	int m = n * (n - 1) / 2;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> a[i][j];
		e[a[i][j]] = { i, j };
	}
	for (int i = 1; i <= m; i++) {
		if (e[i].first > e[i].second) {
			swap(e[i].first, e[i].second);
		}
	}
	vector<pair<int, int>> sub;
	for (int i = 0; i < n; i++)
		sub.emplace_back(i, 1);
	vector<int> compof(n);
	for (int i = 0; i < n; i++) compof[i] = i;
	vector<comp> c(n);
	for (int i = 0; i < n; i++) c[i] = comp(i);
	for (int i = 1; i <= m; i++) {
		if (OO) cout << "edge " << i << '\n';
		int x = e[i].first, y = e[i].second;
		int cx = compof[x], cy = compof[y];
		if (cx == cy) {
			c[cx].cnt++;
			int sz = c[cx].v.size();
			if (sz * (sz - 1) / 2 == c[cx].cnt)
				sub.emplace_back(c[cx].v[0], sz);
		}
		else {
			if (OO) {
				cout << "merging " << cx << " " << cy << '\n';
			}
			for (const auto &j : c[cy].v) {
				compof[j] = cx;
				c[cx].v.push_back(j);
			}
			c[cy].v.clear();
			c[cx].cnt += c[cy].cnt + 1;

			int sz = c[cx].v.size();
			if (OO) {
				cout << "cnt size " << c[cx].cnt << " " << sz << '\n';
			}
			if (sz * (sz - 1) / 2 == c[cx].cnt)
				sub.emplace_back(c[cx].v[0], sz);
		}
	}
	vector<int> ord;
	int finalcomp = compof[0];
	ord = c[finalcomp].v;

	if (OO) {
		for (const auto &i : ord) cout << i << " "; cout << endl;
		for (const auto &i : sub) cout << i.first << " " << i.second << '\n';
	}

	vector<int> posof(n);
	for (int i = 0; i < n; i++)
		posof[ord[i]] = i;
	vector<vector<int>> to(n);
	for (const auto &i : sub) {
		int p = posof[i.first];
		to[p].push_back(i.second + p);
	}

	for (int i = 0; i < n; i++) {
		dp[i][1] = 0;
		for (const auto &s : to[i])
			if (s == n)
				dp[i][1] = 1;
	}
	for (int k = 2; k <= n; k++) {
		for (int i = 0; i < n; i++) {
			dp[i][k] = 0;
			for (const auto &s : to[i]) {
				if (s == n) continue;
				dp[i][k] = (dp[i][k] + dp[s][k - 1]) % md;
			}
		}
	}
	for (int k = 1; k <= n; k++) cout << dp[0][k] << " "; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}