#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

struct xor_basis{
	int d, sz;
	vector<int> basis;

	xor_basis(int d) {
		this->d = d;
		sz = 0;
		basis.resize(d);
	}

	bool add(int mask, int actually_add) {
		if (mask == 0) return 0;
		for (int i = 0; i < d; i++) {
			if (mask & (1 << i)) {
				if (!basis[i]) {
					if (actually_add) {
						basis[i] = mask; 
						sz++;
					}
					return 1;
				}
				mask ^= basis[i];
			}
		}
		return 0;
	}
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q; cin >> n >> q;
	int rs = 1;
	
	vector<tuple<int, int, int>> evs;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		evs.emplace_back(i, 0, x);
	}
	for (int i = 0; i < q; i++) {
		int l, x; cin >> l >> x;
		evs.emplace_back(l-1, i+1, x);
	}
	sort(evs.begin(), evs.end());

	vector<int> ans(q); xor_basis xrb(20);
	for (auto [l, id, x]: evs) {
		if (id == 0) {
			if (!xrb.add(x, 1)) {
				rs = (rs*2) % M;
			}
		} else {
			id--;
			ans[id] = rs*(!xrb.add(x, 0));
		}
	}

	for (int i: ans) cout << i << '\n';

	return 0;
}