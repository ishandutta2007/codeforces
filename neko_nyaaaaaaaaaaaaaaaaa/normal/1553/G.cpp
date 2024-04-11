#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> P, S;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}
	
	int find(int x) {
		if (x == P[x]) return x;
		return P[x] = find(P[x]);
	}
	
	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return 0;
		if (S[a] < S[b]) swap(a, b);
		
		S[a] += S[b];
		P[b] = a;
		return 1;
	}
	
	int same(int a, int b) {
		return find(a) == find(b);
	}
};

const int MAXN = 1000001;

vector<int> dv[MAXN+1];

void init() {
	for (int i = 2; i <= MAXN; i++) {
		if (dv[i].empty()) {
			for (int j = i; j <= MAXN; j += i) {
				dv[j].push_back(i);
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	DSU d(n + MAXN);
	for (int i = 0; i < n; i++) {
		for (int p: dv[a[i]]) {
			d.merge(i, n + p);
		}
	}

	set<pair<int, int>> st;
	for (int i = 0; i < n; i++) {
		for (int p1: dv[a[i]]) {
			for (int p2: dv[a[i] + 1]) {
				int u = d.find(n + p1);
				int v = d.find(n + p2);

				if (u != v) {
					st.insert({u, v});
					st.insert({v, u});
				}
			}
		}

		for (int p1: dv[a[i] + 1]) {
			for (int p2: dv[a[i] + 1]) {
				int u = d.find(n + p1);
				int v = d.find(n + p2);

				if (u != v) {
					st.insert({u, v});
					st.insert({v, u});
				}
			}
		}
	}

	while (q--) {
		int u, v; cin >> u >> v; u--, v--;
		if (d.same(u, v)) {
			cout << "0\n";
		} else {
			u = d.find(u);
			v = d.find(v);

			if (st.find({u, v}) != st.end()) {
				cout << "1\n";
			} else {
				cout << "2\n";
			}
		}
	}

	return 0;
}