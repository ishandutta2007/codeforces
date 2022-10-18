#include <bits/stdc++.h>
using namespace std;

struct scc {
	int n, C = 0, T = 0, top = -1;
	vector<int> comp, t, st;
	vector<vector<int>> adj;

	int dfs(int i) {
		int tmin = t[i] = T++;
		st[++top] = i;
		for (int j: adj[i]) if (comp[j] == -1) {
			tmin = min(tmin, t[j] == -1 ? dfs(j) : t[j]);
		}
		if (tmin == t[i]) {
			while (st[top] != i) comp[st[top--]] = C;
			comp[st[top--]] = C++;
		}
		return tmin;
	}

	scc(vector<vector<int>> adj): n(size(adj)), comp(n,-1), t(n,-1), st(n), adj(adj) {
		for (int i = 0; i < n; i++) {
			if (t[i] == -1) dfs(i);
		}
	}
};

struct sat2 {
	int n;
	vector<vector<int>> adj;
	vector<int> val;

	sat2(int n): n(n), adj(2*n), val(n) { }

	void add(int a, int b) {
		adj[n+a].push_back(n+b);
		adj[n+~b].push_back(n+~a);
	}

	// use these to add new clauses:
	void Or   (int a, int b) { add(~a,b); }
	void True (int a)        { Or(a,a); }
	void False(int a)        { True(~a); }
	void Same (int a, int b) { add(a,b), add(b,a); }
	void Xor  (int a, int b) { Same(a,~b); }

	bool check() { // check for satisfiability and write satisfying valuation to val
		scc S(adj);
		for (int i = 0; i < n; i++) {
			if (S.comp[n+~i] == S.comp[n+i]) return false;
			val[i] = S.comp[n+~i] > S.comp[n+i];
		}
		return true;
	}
};

int parity(int x) {
	return __builtin_popcount(x) % 2;
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	sat2 S(n);

	vector<tuple<int,int,int>> edges(n-1);
	for (auto &[a,b,v]: edges) {
		cin >> a >> b >> v;
		a--, b--;
		if (v >= 0) {
			if (parity(v)) S.Xor(a,b);
			else S.Same(a,b);
		}
	}

	while (m--) {
		int a, b, v;
		cin >> a >> b >> v;
		a--, b--;
		if (v) S.Xor(a,b);
		else S.Same(a,b);
	}
	
	if (S.check()) {
		cout << "YES" << '\n';
		for (auto &[a,b,v]: edges) {
			if (v == -1) {
				v = S.val[a] != S.val[b];
			}
			cout << a+1 << " " << b+1 << " " << v << '\n';
		}
	} else {
		cout << "NO" << '\n';
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}