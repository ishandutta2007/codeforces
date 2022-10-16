#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 998244353;
 
struct STLazy {
	int n;
	vector<int> tr, lz;
 
	STLazy(int n) : n(n), tr(4*n + 8), lz(4*n + 8, 1) {}
 
	void push(int v, int lo, int hi) {
		tr[v] = (1LL * tr[v] * lz[v]) % M;
		if(lo+1 != hi) {
			lz[v*2] = (1LL * lz[v*2] * lz[v]) % M;
			lz[v*2+1] = (1LL * lz[v*2+1] * lz[v]) % M; 
		}
		lz[v] = 1;
	}
 
	void update(int v, int lo, int hi, int l, int r, int val) {
		push(v, lo, hi);
		if (lo >= hi || lo >= r || hi <= l) return;
 
		if (lo >= l && hi <= r) {
			lz[v] = (1LL * lz[v] * val) % M; // put lazy tag here
			push(v, lo, hi);
			return;
		}
 
		int mid = (lo + hi) / 2;
		update(v*2, lo, mid, l, r, val);
		update(v*2 + 1, mid, hi, l, r, val);
 
		tr[v] = (tr[2*v] + tr[2*v+1]) % M;
	}
 
	int query(int v, int lo, int hi, int l, int r) {
		push(v, lo, hi);
		if (lo >= hi || lo >= r || hi <= l) return 0;
 
		if (lo >= l && hi <= r) {
			return tr[v];
		}
 
		int mid = (lo + hi)/2;
		int p1 = query(v*2, lo, mid, l, r);
		int p2 = query(v*2 + 1, mid, hi, l, r);
		
		return (p1 + p2) % M;
	}
 
	void setit(int v, int lo, int hi, int p, int val) {
		if (lo >= hi) return;
		push(v, lo, hi);
		if (lo+1 == hi && lo == p) {
			tr[v] = val;
			return;
		}
		if (lo <= p && hi > p) {
			int mid = (lo + hi) / 2;
			setit(v*2, lo, mid, p, val);
			setit(v*2 + 1, mid, hi, p, val);
 
			tr[v] = (tr[2*v] + tr[2*v+1]) % M;
		}	
	}
 
	void update(int l, int r, int val) {
		if (l >= r) return;
		update(1, 0, n, l, r, val);
	}
 
	void setv(int p, int val) {
		setit(1, 0, n, p, val);
	}
 
	int query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> x(n), y(n), s(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> s[i];
	}

	STLazy st(n);
	vector<int> f(n);
	for (int i = 0; i < n; i++) {
		int dist = (x[i] - y[i]) % M;

		int pos = upper_bound(x.begin(), x.end(), y[i]) - x.begin();
		if (pos < i) {
			dist = (dist + st.query(pos, i)) % M;
		}

		//st.update(0, i, 2);
		st.setv(i, dist);
		f[i] = dist;
	}

	int ans = (x[n-1] + 1) % M;
	for (int i = 0; i < n; i++) {
		//cout << f[i] << ' ';
		if (s[i]) ans = (ans + f[i]) % M;
	}
	//cout << '\n';
	cout << ans << '\n';

	return 0;
}