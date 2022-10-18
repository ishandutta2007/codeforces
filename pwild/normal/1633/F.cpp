#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct hld {
	int n, T = 0;
	bool is_edge;
	vector<int> par, dep, size, up, tin, tout, order;
	vector<vector<int>> children;

	void dfs_size(int i) {
		size[i] = 1;
		for (int &j: children[i]) {
			par[j] = i, dep[j] = dep[i] + 1;
			dfs_size(j);
			size[i] += size[j];
			if (size[j] > size[ children[i][0] ]) swap(j, children[i][0]);
		}
	}

	void dfs_hld(int i) {
		tin[i] = T++;
		order[tin[i]] = i;
		for (int j: children[i]) {
			up[j] = (j == children[i][0] ? up[i] : j);
			dfs_hld(j);
		}
		tout[i] = T;
	}

	hld(vector<int> par, bool is_edge):
			n(par.size()), is_edge(is_edge), par(par), dep(n),
			size(n), up(n), tin(n), tout(n), order(n), children(n) {
		int r = -1;
		for (int i = 0; i < n; i++) {
			if (par[i] == -1) r = i;
			else children[par[i]].push_back(i);
		}
		dfs_size(r), dfs_hld(r);
	}
	
	template<typename F>
	void query(int i, int j, F callback) {
		while (up[i] != up[j]) {
			if (dep[up[i]] < dep[up[j]]) swap(i,j);
			callback(tin[up[i]], tin[i]+1);
			i = par[up[i]];
		}
		if (dep[i] > dep[j]) swap(i,j);
		callback(tin[i]+is_edge, tin[j]+1);
	}
};

template<typename T, typename U>
struct segtree {
	int n, H;
	
	vector<T> value;
	vector<U> prop;
	vector<bool> dirty;

	segtree<T,U>(int n): n(n), H(32 - __builtin_clz(2*n-1)), value(2*n), prop(n), dirty(n) { }
	
	void init(vector<T> leaves) {
		copy(begin(leaves), end(leaves), begin(value)+n);
		for (int i = n-1; i >= 1; i--) {
			value[i] = value[2*i] + value[2*i+1];
		}
	}

	void apply(int i, U &upd) {
		value[i] = upd(value[i]);
		if (i < n) prop[i] = prop[i] + upd, dirty[i] = true;
	}

	void rebuild(int i) {
		for (i /= 2; i; i /= 2) value[i] = prop[i](value[2*i] + value[2*i+1]);
	}

	void propagate(int i) {
		for (int h = H; h >= 1; h--) if (dirty[i >> h]) {
			int j = i >> h;
			apply(2*j,prop[j]), apply(2*j+1,prop[j]);
			prop[j] = U(), dirty[j] = false;
		}
	}

	void update(int i, int j, U upd) {
		if (i == j) return;
		i += n, j += n;
		propagate(i), propagate(j-1);
		for (int l = i, r = j; l < r; l /= 2, r /= 2) {
			if (l & 1) apply(l++,upd);
			if (r & 1) apply(--r,upd);
		}
		rebuild(i), rebuild(j-1);
	}
	
	T query(int i, int j) {
		i += n, j += n;
		propagate(i), propagate(j-1);
		T resl, resr;
		for (; i < j; i /= 2, j /= 2) {
			if (i & 1) resl = resl + value[i++];
			if (j & 1) resr = value[--j] + resr;
		}
		return resl + resr;
	}
};

struct node {
	int a = 0, b = 0;
	node operator+(node n) { return {a+n.a, b+n.b}; }
};

struct update {
	bool flip = false;
	node operator()(node n) { return flip ? node{n.b,n.a} : n; }
	update operator+(update u) { return {flip != u.flip}; }
};

// use HLD to maintain the number of nodes with even subtree size

int main() {
	int n; cin >> n;

	vector<vector<pair<int,int>>> adj(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].emplace_back(b,i);
		adj[b].emplace_back(a,i);
	}

	vector<int> par(n, -1);
	auto dfs_par = [&](auto &self, int i) -> void {
		for (auto [j,k]: adj[i]) if (j != par[i]) {
			par[j] = i; self(self, j);
		}
	};
	dfs_par(dfs_par, 0);

	hld H(par, false);

	vector<i64> dp(n);
	for (int i: H.order) if (i != 0) {
		for (auto [j,k]: adj[i]) if (j == par[i]) dp[i] += k;
		if (par[i] != 0) dp[i] += dp[ par[par[i]] ];
	}

	i64 sum = 0, cnt = 0, odd_cnt = 0;
	vector<int> mark(n);
	segtree<node,update> S(n);
	S.init(vector<node>(n, {1,0}));

	auto flip = [&](int i, int j) {
		auto x = S.query(i, j);
		odd_cnt += x.a - x.b;
		S.update(i, j, {true});
	};
	
	mark[0] = 1, cnt++;
	flip(0, 1);

	vector<int> use_edge;
	auto dfs_match = [&](auto &self, int i) -> bool {
		bool res = true;
		for (auto [j,k]: adj[i]) if (j != par[i] && mark[j]) {
			if (self(self, j)) use_edge[k] = 1, res = false;
		}
		return res;
	};

	while (true) {
		int type; cin >> type;
		if (type == 1) {
			int i; cin >> i; i--;
			mark[i] = 1, cnt++;
			sum += dp[i] - dp[par[i]];

			H.query(0, i, flip);

			cout << (2*odd_cnt == cnt ? sum : 0) << endl;
		} else if (type == 2) {
			if (2*odd_cnt == cnt) {
				use_edge.assign(n, 0);
				dfs_match(dfs_match, 0);
				cout << odd_cnt;
				for (int i = 1; i < n; i++) if (use_edge[i]) cout << " " << i;
				cout << endl;
			} else {
				cout << 0 << endl;
			}
		} else if (type == 3) {
			break;
		} else {
			assert(0);
		}
	}
}