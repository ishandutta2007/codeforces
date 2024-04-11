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

int ask(int u) {
	cout << "? " << u << endl;
	int x; cin >> x; return x;
}

void answer(vector<int> v, int n) {
	cout << "!";
	for (int i = 1; i <= n; i++) {
		cout << ' ' << v[i];
	}
	cout << endl;
}

void solve() {
	int n; cin >> n;
	vector<int> dg(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> dg[i];
	}

	DSU d(n+1);
	vector<int> used(n+1);
	while (true) {
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			if (used[i]) continue;
			if (mx == 0) mx = i;
			if (dg[i] > dg[mx]) mx = i;
		}
		if (mx == 0) break;

		int collide = 0;
		for (int i = 0; i < dg[mx]; i++) {
			int nxt = ask(mx);
			if (used[nxt]) {
				collide = nxt; break;
			} else {
				d.merge(mx, nxt);
			}
		}

		int pr = d.find(mx);
		for (int i = 1; i <= n; i++) {
			if (d.find(i) == pr) used[i] = 1;
		}

		if (collide != 0) {
			d.merge(mx, collide);
		}
	}

	vector<int> ans(n+1);
	for (int i = 1; i <= n; i++) {
		ans[i] = d.find(i);
	}
	answer(ans, n);
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}