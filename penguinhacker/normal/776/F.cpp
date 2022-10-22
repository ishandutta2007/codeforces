#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#define debug(x) cerr << "[" << #x << "] = [" << x << "]\n"

template<class A, class B> ostream& operator<< (ostream& out, pair<A, B> p) {
	return out << '[' << p.first << ", " << p.second << ']';
}

template<class A, int sz> ostream& operator<< (ostream& out, ar<A, sz> a) {
	out << '[';
	for (int i = 0; i < sz; ++i) {
		if (i > 0) out << ", ";
		out << a[i];
	}
	return out << ']';
}

template<class T> ostream& operator<< (ostream& out, vector<T>& v) {
	out << '[';
	for (int i = 0; i < v.size(); ++i) {
		if (i > 0) {
			out << ", ";
		}
		out << v[i];
	}
	return out << ']';
}

const int mxN = 100000;
int n, m, nxt[mxN];
pair<int, int> diag[mxN];
vector<vector<int>> regions;

void add_diagonal(int a, int b) {
	vector<int> v;
	int cur = a;
	while(cur != b) {
		v.push_back(cur);
		cur = nxt[cur];
	}
	v.push_back(b);
	nxt[a] = b;

	sort(v.rbegin(), v.rend());
	regions.push_back(v);
}

bool comp(vector<int>& a, vector<int>& b) {
	for (int i = 0; i < a.size() && i < b.size(); ++i) {
		if (a[i] == b[i]) continue;
		return a[i] < b[i];
	}
	assert(a.size() != b.size());
	return a.size() < b.size();
}

map<pair<int, int>, vector<int>> mp;
vector<int> adj[mxN];

void make_graph() {
	cin >> n >> m;
	if (m == 0) {
		cout << 1;
		exit(0);
	}
	iota(nxt, nxt + n, 1);
	nxt[n - 1] = 0;
	for (int i = 0; i < m; ++i)
		cin >> diag[i].first >> diag[i].second, --diag[i].first, --diag[i].second;
	auto Calc = [&](pair<int, int> p) {
		int x = abs(p.first - p.second);
		return min(x, n - x);
	};
	sort(diag, diag + m, [&](pair<int, int> a, pair<int, int> b) {return Calc(a) < Calc(b);});
	for (int i = 0; i < m; ++i) {
		int a = diag[i].first, b = diag[i].second;
		if ((b - a + n) % n > n / 2) swap(a, b);
		add_diagonal(a, b);
		if (i == m - 1) add_diagonal(b, a);
	}
	sort(regions.begin(), regions.end(), comp);
	assert(regions.size() == m + 1);
	//debug(regions);
	for (int i = 0; i <= m; ++i) {
		vector<int>& v = regions[i];
		reverse(v.begin(), v.end());
		for (int j = 0; j < v.size(); ++j) {
			int a = v[j], b = v[(j + 1) % v.size()];
			if (a > b) swap(a, b);
			mp[{a, b}].push_back(i);
		}
	}
	for (auto& x : mp) {
		vector<int>& v = x.second;
		assert(1 <= v.size() && v.size() <= 2);
		if (v.size() == 1) continue;
		int a = v[0], b = v[1];
		adj[a].push_back(b);
		adj[b].push_back(a);
		//cout << a << " " << b << "\n";
	}
}

int sz[mxN], ans[mxN];
bool dead[mxN];

int dfs_sz(int u, int p) {
	sz[u] = 1;
	for (int v : adj[u]) if (v != p && !dead[v])
		sz[u] += dfs_sz(v, u);
	return sz[u];
}

int get_centroid(int u, int p, int tsz) {
	for (int v : adj[u]) if (v != p && !dead[v] && 2 * sz[v] > tsz)
		return get_centroid(v, u, tsz);
	return u;
}

void centroid(int u = 0, int d = 1) {
	u = get_centroid(u, -1, dfs_sz(u, -1));
	ans[u] = d;
	dead[u] = 1;
	for (int v : adj[u]) if (!dead[v])
		centroid(v, d + 1);
	dead[u] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_graph();
	centroid();
	for (int i = 0; i <= m; ++i)
		cout << ans[i] << " ";
	return 0;
}