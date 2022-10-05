#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int b = 14;
const int N = 1 << b;

int n;
int a[20][20];

vector<ll> dp[b][N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		char c;
		cin >> c;
		a[i][j] = c - '0';
	}
	for (int i = 0; i < (1 << n); i++) {
		vector<int> pos;
		for (int j = 0; j < b; j++)
			if (i & (1 << j))
				pos.push_back(j);
		if (pos.size() == 0) continue;
		if (pos.size() == 1) {
			dp[pos[0]][i].push_back(1);
			continue;
		}
		int sz = 1 << (pos.size() - 1);
		for (const auto &u : pos) {
			// dp[u][i]
			dp[u][i].resize(sz);
			int vmask = i ^ (1 << u);
			for (const auto &v : pos) {
				if (u != v) {
					for (int path = a[u][v]; path < sz; path += 2)
						dp[u][i][path] += dp[v][vmask][path / 2];
				}
			}
		}
	}
	vector<ll> ans(1 << (n - 1), 0);
	for (int v = 0; v < n; v++) {
		for (int i = 0; i < dp[v][(1 << n) - 1].size(); i++)
			ans[i] += dp[v][(1 << n) - 1][i];
	}
	for (const auto &i : ans) cout << i << " "; cout << '\n';
}