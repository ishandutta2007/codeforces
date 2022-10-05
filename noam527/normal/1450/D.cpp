#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;
vector<int> pos[300003];

void output(const vector<int> &ans) {
	for (int i = 1; i <= n; i++) cout << ans[i];
	cout << '\n';
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) pos[i].clear();
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 0; i < n; i++) {
		pos[a[i]].push_back(i);
	}
	vector<int> ans(n + 1, 0);
	ans[1] = 1;
	for (int i = 1; i <= n; i++)
		if (!pos[i].size()) ans[1] = 0;

	int l = 0, r = n - 1, nxt = 1;
	while (l <= r) {
		if (pos[nxt].size() == 0) {
			output(ans);
			return;
		}
		ans[r - l + 1] = 1;
		if (pos[nxt].size() >= 3) {
			output(ans);
			return;
		}
		for (auto x : pos[nxt]) {
			if (l < x && x < r) {
				output(ans);
				return;
			}
		}
		if (pos[nxt].size() == 2) {
			output(ans);
			return;
		}
		if (pos[nxt][0] == l) l++;
		else r--;
		nxt++;
	}
	output(ans);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}