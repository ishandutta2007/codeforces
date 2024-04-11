#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

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

		tr[v] = max(tr[2*v], tr[2*v+1]);
	}

	int query(int v, int lo, int hi, int l, int r) {
		push(v, lo, hi);
		if (lo >= hi || lo >= r || hi <= l) return -INF;

		if (lo >= l && hi <= r) return tr[v];

		int mid = (lo + hi)/2;
		int p1 = query(v*2, lo, mid, l, r);
		int p2 = query(v*2 + 1, mid, hi, l, r);
		
		return max(p1, p2);
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
	
	int n, q; cin >> n >> q;
	vector<int> lazy(n+1);
	set<pair<int, int>> st;
	st.insert({1, 1}); // id, color
	st.insert({n+1, 998244353});
	STLazy tr(n+2);	

	while (q--) {
		string s; cin >> s;
		if (s == "Color") {
			int l, r, c; cin >> l >> r >> c; r++;

			{
				auto it = st.lower_bound({l, -1});
				if (it->first != l) {
					it--; int col = it->second;
					st.insert({l, col});
				}
			}
			{
				auto it = st.lower_bound({r, -1});
				if (it->first != r) {
					it--; int col = it->second;
					st.insert({r, col});
				}
			}

			while (1) {
				auto it = st.lower_bound({l, -1});
				if (it->first >= r) break;
				int L = it->first, colfi = it->second;
				it++; int R = it->first; it--;

				st.erase(it); 

				int colse = c;
				int upd = lazy[colfi] - lazy[colse];
				tr.update(L, R, upd);				
			}
			st.insert({l, c});

		} else if (s == "Add") {
			int c, x; cin >> c >> x;
			lazy[c] += x;
		} else if (s == "Query") {
			int i; cin >> i;
			auto it = st.lower_bound({i+1, -1});
			it--;

			int ans = tr.query(i, i+1);
			ans += lazy[it->second];
			cout << ans << '\n';
		}
	}

	return 0;
}