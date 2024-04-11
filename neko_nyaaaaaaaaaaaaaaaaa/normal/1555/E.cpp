#include <bits/stdc++.h>
using namespace std;

const int INF = 10000000;

struct STLazy {
	int n;
	vector<int> tr, lz;

	STLazy(int n) : n(n), tr(4*n + 8), lz(4*n + 8) {}

	void push(int v, int lo, int hi) {
		if (lz[v] != 0) {
			tr[v] += lz[v];
			if(lo+1 != hi) {
				lz[v*2] += lz[v];
				lz[v*2+1] += lz[v]; 
			}
			lz[v] = 0;
		}
	}

	void update(int v, int lo, int hi, int l, int r, int val) {
		push(v, lo, hi);
		if (lo >= hi || lo >= r || hi <= l) return;

		if (lo >= l && hi <= r) {
			lz[v] += val;
			push(v, lo, hi);
			return;
		}

		int mid = (lo + hi) / 2;
		update(v*2, lo, mid, l, r, val);
		update(v*2 + 1, mid, hi, l, r, val);

		tr[v] = min(tr[2*v], tr[2*v+1]);
	}

	int query(int v, int lo, int hi, int l, int r) {
		push(v, lo, hi);
		if (lo >= hi || lo >= r || hi <= l) return INF;

		if (lo >= l && hi <= r) return tr[v];

		int mid = (lo + hi)/2;
		int p1 = query(v*2, lo, mid, l, r);
		int p2 = query(v*2 + 1, mid, hi, l, r);
		
		return min(p1, p2);
	}

	void update(int l, int r, int val) {
		update(1, 0, n, l, r, val);
	}

	int query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>> segs;
	for (int i = 0; i < n; i++) {
		int l, r, w; cin >> l >> r >> w;
		l--; r--;
		segs.emplace_back(w, l, r);
	}
	sort(segs.begin(), segs.end());

	int ans = 1000000;
	STLazy st(m-1);

	int petr = 0;
	for (int i = 0; i < n; i++) {
		while (petr < n && st.query(0, m-1) == 0) {
			auto [w, l, r] = segs[petr];
			st.update(l, r, 1);
			petr++;
		}
		if (st.query(0, m-1) == 0) break;

		ans = min(ans, get<0>(segs[petr-1]) - get<0>(segs[i]));
		auto [w, l, r] = segs[i];
		st.update(l, r, -1);
	}
	cout << ans << '\n';

	return 0;
}