#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;

void unify_p2(int l, int r, vector<int> &v) {
	if (l+1 == r) return;
	int mid = (l+r)/2;
	unify_p2(l, mid, v);
	unify_p2(mid, r, v);

	for (int i = l, j = mid; i < mid; i++, j++) {
		ans.emplace_back(v[i], v[j]);
	}
}  

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<vector<int>> groups;
	int petr = 1;
	for (int i = 0; i < 14; i++) {
		if (n & (1 << i)) {
			int j = (1 << i);
			vector<int> gs;
			while (j--) {
				gs.push_back(petr);
				petr++;
			}
			groups.push_back(gs);
		}
	}	

	for (auto v: groups) {
		unify_p2(0, v.size(), v);
	}

	vector<int> biggest = groups.back();
	groups.pop_back();

	reverse(groups.begin(), groups.end());
	while (groups.size() > 1) {
		auto v1 = groups.back(); groups.pop_back();
		auto v2 = groups.back(); groups.pop_back();

		int s1 = v1.size(), s2 = v2.size();
		while (s1 < s2) {
			// borrow exactly s1 copies from biggest
			vector<int> ns;
			int g = s1;
			while (g--) {
				ns.push_back(biggest.back()); 
				biggest.pop_back();
			}

			vector<int> nxt;
			for (int i = 0; i < s1; i++) {
				ans.emplace_back(ns[i], v1[i]);
				nxt.push_back(ns[i]);
				nxt.push_back(v1[i]);
			}
			v1 = nxt;

			s1 *= 2;
		}

		vector<int> nxt;
		for (int i = 0; i < s1; i++) {
			ans.emplace_back(v2[i], v1[i]);
			nxt.push_back(v2[i]);
			nxt.push_back(v1[i]);
		}
		groups.push_back(nxt);
	}

	cout << ans.size() << '\n';
	for (auto [u, v]: ans) cout << u << ' ' << v << '\n';

	return 0;
}