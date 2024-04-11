#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int n, vector<pair<int, int>> a, int md) {
	vector<pair<int, int>> evs;
	for (auto [l, r]: a) {
		if (r-l+1 >= md) {
			evs.emplace_back(0, 1);
			evs.emplace_back(md, -1);
		} else if (l/md == r/md) {
			if ((r%md) == md-1) {
				evs.emplace_back(l%md, 1);
				evs.emplace_back(md, -1);
			} else {
				evs.emplace_back(l%md, 1);
				evs.emplace_back((r+1)%md, -1);
			}
		} else {
			evs.emplace_back(l%md, 1);
			evs.emplace_back(md, -1);

			evs.emplace_back(0, 1);
			evs.emplace_back((r+1)%md, -1);
		}
	}
	sort(evs.begin(), evs.end());

	int prv = -1, cur = 0, ans = 0;
	for (auto [x, i]: evs) {
		if (x != prv) {
			ans = max(ans, cur);
			prv = x;
		}
		cur += i;
	}

	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<pair<int, int>> a;
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r; r--, l--;
		a.emplace_back(l, r);
	}

	vector<int> ans;
	for (int i = 0; i < 30; i++) {
		ans.push_back(solve(n, a, (1 << i)));
	}

	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		for (int i = 0; i < 30; i++) {
			if (x & (1 << i)) {
				cout << ans[i] << '\n';
				break;
			}
		}
	}

	return 0;
}