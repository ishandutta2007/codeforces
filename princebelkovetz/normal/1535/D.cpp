#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
struct tree {
	int n;
	vector <int> t, dp;
	tree(int n) : n(n) {
		t.resize(2 * n + 3);
		dp.resize(2 * n + 3, 1);
	}
	void recalc(int v) {
		if (t[v] == 0) dp[v] = dp[2 * v + 1];
		if (t[v] == 1) dp[v] = dp[2 * v];
		if (t[v] == 2) dp[v] = dp[2 * v] + dp[2 * v + 1];
		if (!v) return;
		recalc(v / 2);
	}
	void query(int i, int ty) {
		t[i] = ty;
		recalc(i);
	}
};
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	tree Tree((1 << n) - 1);
	string s; cin >> s;
	for (int i = 0; i < Tree.n; ++i) {
		char c = s[i];
		if (c == '0') Tree.query(Tree.n - i, 0);
		if (c == '1') Tree.query(Tree.n - i, 1);
		if (c == '?') Tree.query(Tree.n - i, 2);
	}
	int q; cin >> q;
	while (q --> 0) {
		int i; char c;
		cin >> i >> c;
		i = Tree.n - i + 1;
		if (c == '0') Tree.query(i, 0);
		if (c == '1') Tree.query(i, 1);
		if (c == '?') Tree.query(i, 2);
		cout << Tree.dp[1] << '\n';
	}
}