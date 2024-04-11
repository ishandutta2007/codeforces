#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}


const int N = 1e5 + 10;
vi g[N];
int dfsctr, root, child;
int dfs_num[N], dfs_low[N], is_art[N];
void dfs_pre(int u, int p)
{
	dfs_num[u] = dfs_low[u] = dfsctr++;
	for (auto it : g[u])
	{
		if (dfs_num[it] == -1)
		{
			if (u == root)++child;
			dfs_pre(it, u);
			dfs_low[u] = min(dfs_low[u], dfs_low[it]);
			if (dfs_low[it] >= dfs_num[u])
				is_art[u] = 1;
		}
		else if (p != it)
		{
			dfs_low[u] = min(dfs_low[u], dfs_num[it]);
		}
	}
}
void pre(int n) {
	dfsctr = 0;
	memset(dfs_num, -1, sizeof(dfs_num));
	FOR(i, 1, n)
	if (dfs_num[i] == -1) {
		root = i, child = 0;
		dfs_pre(root, -1);
		is_art[root] = child > 1;
	}
}
int p[N], vis[N], d[N];
int jump[21][N];
int lca(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	NFOR (i, 20, 0) if (jump[i][u] and d[jump[i][u]] >= d[v]) u = jump[i][u];
	assert(d[u] == d[v]);
	if (u == v) return u;
	NFOR (i, 20, 0) if (jump[i][u] and jump[i][v] and jump[i][u] != jump[i][v]) {
		u = jump[i][u];
		v = jump[i][v];
	}
	return p[u];
}
int get(int k, int u) {
	FOR (i, 0, 20) if (k & (1 << i)) u = jump[i][u];
	return u;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, q; cin >> n >> m >> q;
	while (m--) {
		int x, y; cin >> x >> y;
		g[x].push_back(y); g[y].push_back(x);
	}
	FOR (i, 1, n) sort(all(g[i]));
	pre(n);
	int r = 0;
	FOR (i, 1, n) if (is_art[i]) r = i;
	if (r) {
		p[r] = 0; vis[r] = 1; queue<int> q;
		q.push(r);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : g[u]) if (!vis[v]) {
				vis[v] = 1;
				d[v] = d[u] + 1;
				p[v] = u;
				q.push(v);
			}
		}
		FOR (i, 1, n) jump[0][i] = p[i];
		FOR (i, 1, 20) FOR (j, 1, n) jump[i][j] = jump[i-1][jump[i-1][j]];
	}
	
	while (q--) {
		int a, b; cin >> a >> b;
		if (r == 0) {
			cout << "1\n";
		} else {
			int l = lca(a, b);
			if (a == l or b == l) {
				cout << d[a]+d[b]-2*d[l] << "\n";
			} else {
				int ans = d[a]+d[b]-2*d[l];
				int A = get(d[a] - d[l] - 1, a), B = get(d[b]-d[l]-1, b);
				if (binary_search(all(g[A]), B)) --ans;
				cout << ans << "\n";
			}
		}
	}


	return 0;
}