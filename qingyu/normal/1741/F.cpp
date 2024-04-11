#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<tuple<int, int, int, int>> segments;
	for (int i = 0; i < n; ++i) {
		int l, r, c;
		cin >> l >> r >> c;
		segments.emplace_back(l, r, c, i);
	}
	vector<int64_t> ans(n, 1e18);
	auto go = [&](auto &segments) {
		sort(segments.begin(), segments.end());
		int64_t mc = -1, mx = -2e9, mid = -1, sc = -1, sx = -2e9, sid = -1;
		auto get = [&](int l, int r, int p) -> int64_t {
			if (p > l)
				return 0;
			return l - p;
		};
		vector<pair<int, vector<int64_t>>> candidates;
		bool updated = false;
		for (auto &[l, r, c, id] : segments) {
			if (c != mc && mc != -1) {
				auto t = get(l, r, mx);
				ans[id] = min(ans[id], t);
				ans[mid] = min(ans[mid], t);
			}
			else if (sc != -1) {
				auto t = get(l, r, sx);
				ans[id] = min(ans[id], t);
				ans[sid] = min(ans[sid], t);
			}
			if (r > mx) {
				if (c == mc) {
					if (r > mx) {
						mx = r;
						mid = id;
					}
				}
				else {
					sc = mc, sx = mx, sid = mid;
					mc = c, mx = r, mid = id;
				}
			}
			else if (r > sx && c != mc) {
				sx = r, sc = c, sid = id;
			}
	
		}
		vector<vector<tuple<int, int, int, int>>> col(n + 1);
		set<tuple<int, int, int, int>> s;
		for (auto &[l, r, c, id] : segments) {
			col[c].emplace_back(l, r, c, id);
			s.emplace(l, r, c, id);
		}

		for (int c = 1; c <= n; ++c) {
			for (auto p : col[c]) {
				s.erase(p);
			}
			for (auto [l, r, c, id] : col[c]) {
				auto p = make_tuple(l, r, c, id);
				auto pp = make_tuple(l, -1, -1, -1);
				auto it = s.lower_bound(pp);
				if (it == s.end()) continue;
				if (::get<0>(*it) <= r) {
					ans[id] = 0;
				}
			}
			for (auto p : col[c]) {
				s.emplace(p);
			}
		}
	};
	go(segments);
	for (auto &[l, r, c, id] : segments) {
		swap(l, r);
		l = -l, r = -r;
	}
	go(segments);
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " \n"[i == n - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}