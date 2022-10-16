#include <bits/stdc++.h>
using namespace std;

int n;
map<int, vector<tuple<int, int, int>>> mp;
vector<pair<int, int>> ans;

vector<tuple<int, int, int>> spare;

void solve(vector<tuple<int, int, int>> a) {
	if (spare.size()) {
		auto [x, y, id] = spare[0];
		spare.clear();

		// match this point with some point in a
		int bx = x, by = y, boxid = 0, erid = -1;
		for (int i = 0; i < a.size(); i++) {
			auto [xx, yy, ii] = a[i];
			if (erid == -1) {
				bx = xx, by = yy, boxid = ii, erid = i;
			} else {
				if (min(x, bx) <= xx && xx <= max(x, bx) && min(y, by) <= yy && yy <= max(y, by)) {
					bx = xx, by = yy, boxid = ii, erid = i;
				}
			}
		}
		ans.emplace_back(id, boxid);
		a.erase(a.begin() + erid);
	}

	map<int, vector<pair<int, int>>> mpp;
	for (auto [x, y, id]: a) {
		mpp[y].emplace_back(x, id);
	}

	pair<int, int> sp;
	int has_sp = -998244353;

	for (auto [yy, u]: mpp) {
		if (has_sp != -998244353) {
			has_sp = -998244353;

			auto [x, id] = sp;

			int bx = x, boxid = 0, erid = -1; 
			for (int i = 0; i < u.size(); i++) {
				auto [xx, ii] = u[i];
				if (erid == -1) {
					bx = xx, boxid = ii, erid = i;
				} else {
					if (min(x, bx) <= xx && xx <= max(x, bx)) {
						bx = xx, boxid = ii, erid = i;
					}
				}
			}
			ans.emplace_back(id, boxid);
			u.erase(u.begin() + erid);
		}

		sort(u.begin(), u.end());
		int m = u.size();
		for (int i = 1; i < m; i += 2) {
			ans.emplace_back(u[i].second, u[i-1].second);
		}
		if (m % 2) {
			has_sp = yy;
			sp = u.back();
		}
	}

	if (has_sp != -998244353) {
		spare.emplace_back(sp.first, has_sp, sp.second);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, z; cin >> x >> y >> z;
		mp[z].emplace_back(x, y, i);
	}

	for (auto u: mp) {
		solve(u.second);
	}

	for (auto [x, y]: ans) {
		cout << x << ' ' << y << '\n';
	}

	return 0;
}