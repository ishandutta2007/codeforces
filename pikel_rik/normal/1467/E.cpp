#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<bool> f(n);
	vector<vector<bool>> que(n);
	vector<int> cnt(n);
	vector<map<int, int>> mp(n);

	auto dfs = [&](int x, int p, const auto &self) -> map<int, int> {
		map<int, int> mp;
		que[x].assign(g[x].size(), true);
		mp[a[x]]++;
		for (int ind = 0; ind < int(g[x].size()); ind++) {
			int i = g[x][ind];
			if (i != p) {
				auto mpi = self(i, x, self);
				que[x][ind] = f[i] && mpi[a[x]] == 0;
				if (mpi.size() > mp.size()){
					mp.swap(mpi);
				}
				for (auto &[k, v] : mpi) {
					mp[k] += v;
				}
				mpi.clear();
			}
		}
		cnt[x] = mp[a[x]];
		f[x] = true;
		for (auto b : que[x]) {
			f[x] = f[x] && b;
		}
		return mp;
	};

	auto total_cnt = dfs(0, -1, dfs);

	vector<bool> ok(n);
	ok[0] = f[0];

	auto reroot = [&](int x, int p, const auto &self) -> void {
		vector<bool> pref(que[x].begin(), que[x].end());
		for (int ind = 1; ind < int(g[x].size()); ind++) {
			pref[ind] = pref[ind] && pref[ind - 1];
		}
		
		vector<bool> suf(que[x].begin(), que[x].end());
		for (int ind = int(g[x].size()) - 2; ind >= 0; ind--) {
			suf[ind] = suf[ind] && suf[ind + 1];
		}

		for (int ind = 0; ind < int(g[x].size()); ind++) {
			int i = g[x][ind];
			bool pref_val = (ind == 0 ? true : pref[ind - 1]);
			bool suf_val = (ind == int(g[x].size()) - 1 ? true : suf[ind + 1]);
			if (i != p) {
				int c = total_cnt[a[i]] - cnt[i];
				bool ok_to_recurse = pref_val && suf_val && c == 0 && g[i].size() > 1 && a[i] != a[x];
				ok[i] = total_cnt[a[i]] == 1 && f[i] && pref_val && suf_val;
				if (ok_to_recurse) {
					self(i, x, self);
				}
			}
		}
	};

	reroot(0, -1, reroot);
	cout << count(ok.begin(), ok.end(), true) << '\n';
	return 0;
}