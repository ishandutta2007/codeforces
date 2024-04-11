#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define debug(x) cerr << '[' << #x << "] = [" << x << "]\n";

template<class A, class B> ostream& operator<< (ostream& out, const pair<A, B>& p) {
	return out << "[" << p.first << ", " << p.second << "]";
}

template<class A> ostream& operator<< (ostream& out, const map<A, int>& m) {
	for (auto it = m.begin(); it != m.end(); ++it) {
		out << "[" << it->first << ": " << it->second << "]";
		if (next(it) != m.end()) {
			out << ", ";
		}
	}
	return out;
}

int binPow(ll b, int p, const int MOD) {
	ll res = 1;
	while(p > 0) {
		if (p & 1) {
			res = res * b % MOD;
		}
		b = b * b % MOD;
		p >>= 1;
	}
	return res;
}

const int mxN = 100000;
int n, M, totient;
vector<ar<int, 2>> adj[mxN];

int sz[mxN];
bool dead[mxN];
ll ans = 0;

int get_centroid(int start) {
	function<void (int, int)> dfs1 = [&](int u, int p) {
		sz[u] = 1;
		for (auto& x : adj[u]) {
			int v = x[0];
			if (!dead[v] && v != p) {
				dfs1(v, u);
				sz[u] += sz[v];
			}
		}
	};
	dfs1(start, -1);
	function<int (int, int)> dfs2 = [&](int u, int p) {
		//debug(u);
		for (auto& x : adj[u]) {
			int v = x[0];
			if (!dead[v] && v != p && 2 * sz[v] > sz[start]) {
				return dfs2(v, u);
			}
		}
		return u;
	};
	return dfs2(start, -1);
}

map<int, int> m1;
map<pair<int, int>, int> m2;
void dfs1(int u, int p, int cur, int p10, int inc) { //goes up
	m1[cur] += inc;
	for (auto& x : adj[u]) {
		int v = x[0], dig = x[1];
		if (!dead[v] && v != p) {
			dfs1(v, u, (cur + (ll)p10 * dig) % M, p10 * 10ll % M, inc);
		}
	}
}

void dfs2(int u, int p, int cur, int d) {
	++m2[pair<int, int>(cur, d)];
	for (auto& x : adj[u]) {
		int v = x[0], dig = x[1];
		if (!dead[v] && v != p) {
			dfs2(v, u, (10ll * cur + dig) % M, d + 1);
		}
	}
}

void add_up() {
	//debug(m1);
	//debug(m2);
	//cout << "\n";
	for (auto& x : m2) {
		pair<int, int> p = x.first;
		int cur = (M - p.first) % M;
		/*if (p.first == 99937) {
			debug(cur);
		}*/
		int inv = binPow(10, p.second, M);
		inv = binPow(inv, totient - 1, M);
		cur = (ll)cur * inv % M;
		/*if (p.first == 99937) {
			debug(cur);
		}*/
		auto it = m1.find(cur);
		if (it != m1.end()) {
			ans += (ll)x.second * (it -> second);
		}
	}
	m1.clear();
	m2.clear();
}

void centroid(int u) {
	u = get_centroid(u);
	//cout << u << "\n";
	dead[u] = 1;
	dfs1(u, -1, 0, 1 % M, 1);
	dfs2(u, -1, 0, 0);
	add_up();
	--ans;
	//debug(u);
	//debug(ans);
	//cout << u << " " << ans << "\n";
	for (auto& v : adj[u]) {
		if (!dead[v[0]]) {
			dfs1(v[0], u, v[1], 10 % M, -1);
			dfs2(v[0], u, v[1], 1);
			add_up();
		}
	}
	//debug(u);
	//debug(ans);
	//cout << u << " " << ans << "\n";
	//cerr << "\n";
	for (auto& x : adj[u]) {
		int v = x[0];
		if (!dead[v]) {
			centroid(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> M;
	if (M == 1) {
		cout << (ll)n * (n - 1);
		return 0;
	}
	int temp = M;
	totient = M;
	for (int i = 2; i * i <= temp; ++i) {
		if (temp % i > 0) continue;
		while (temp % i == 0) temp /= i;
		totient = totient / i * (i - 1);
	}
	if (temp > 1) {
		totient = totient / temp * (temp - 1);
	}
	for (int i = 1; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		c %= M;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	//ans = -n;
	centroid(0);
	cout << ans;
	return 0;
}