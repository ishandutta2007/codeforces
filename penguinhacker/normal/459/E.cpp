#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, mxW=1e5;
int n, m, dp[mxN];
vector<ar<int, 2>> edge[mxW];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c, --a, --b, --c;
		edge[c].push_back({a, b});
	}
	for (int i = 0; i < mxW; ++i) {
		map<int, int> last;
		for (auto& x : edge[i])
			last[x[0]] = dp[x[0]];
		for (auto& x : edge[i])
			dp[x[1]] = max(dp[x[1]], last[x[0]] + 1);
	}
	cout << *max_element(dp, dp + n);
	return 0;
}