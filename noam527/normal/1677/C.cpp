#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a, b;
vector<int> to, vis;

int dfs(int v) {
	if (vis[v]) return 0;
	vis[v] = 1;
	return 1 + dfs(to[v]);
}

void solve() {
	cin >> n;
	a.resize(n), b.resize(n);
	for (auto &i : a) cin >> i, --i;
	for (auto &i : b) cin >> i, --i;
	to.resize(n);
	for (int i = 0; i < n; i++)
		to[a[i]] = b[i];
	vis.resize(n);
	for (auto &i : vis) i = 0;
	vector<int> sz;
	for (int i = 0; i < n; i++) {
		if (!vis[i])
			sz.push_back(dfs(i));
	}
	int l = 0, r = n - 1;
	ll cnt = 0;
	for (auto &i : sz) {
		if (i & 1) {
			i--, cnt++;
		}
	}
	vector<int> res(n, -1);
	for (auto &s : sz) {
		if (s == 0) {
			continue;
		}

		int sl = s / 2;
		int nxtl = l, nxtr = r - sl + 1;
		for (int i = 0; i < sl; i++) {
			res[nxtl] = nxtr;
			if (i + 1 < sl)
				res[nxtr] = nxtl + 1;
			else {
				res[nxtr] = l;
			}
			nxtl++, nxtr++;
		}

		l += s / 2;
		r -= s / 2;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		if (res[i] != -1)
			ans += abs(i - res[i]);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}