#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &i: a) cin >> i;

	sort(a.begin(), a.end());
	vector<int> b;
	for (int i = 1; i < n; i++) {
		b.push_back(a[i] - a[i-1]);
	}
	sort(b.begin(), b.end());

	int q; cin >> q;
	vector<tuple<int, int>> que;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		que.emplace_back(r - l + 1, i);
	}
	sort(que.begin(), que.end());

	vector<int> ans(q);
	int petr = 0, left = n, sum = 0;
	for (auto u: que) {
		int x, i;
		tie(x, i) = u;
		while (petr < n-1 && b[petr] < x) {
			sum += b[petr];
			petr++; left--;
		}
		ans[i] = sum + left*x;
	}

	for (int i: ans) cout << i << ' ';

	return 0;
}