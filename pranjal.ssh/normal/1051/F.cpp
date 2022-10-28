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

vi p, st, en;
vector<ll> l;
vector<vi> jump;
int n;
vector<vector<ii>> g, G;

void dfs(int u) {
   static int ctr = 0;
   st[u] = ++ctr;
   for (auto it : g[u]) {
      if (it.F == p[u]) continue;
      p[it.F] = u;
      l[it.F] = l[u] + it.S;
      dfs(it.F);
   }
   en[u] = ctr;
}

void pre() {
   jump = vector<vi>(17, vi(n + 1));
   st = en = p = vi(n + 1);
   l.resize(n + 1);
   dfs(1);
   FOR (i, 1, n) jump[0][i] = p[i];
   FOR (i, 1, 16) {
      FOR (j, 1, n) {
         jump[i][j] = jump[i - 1][jump[i - 1][j]];
      }
   }
}

int lca(int u, int v) {
   if (st[u] >= st[v] and st[u] <= en[v]) return v;
   NFOR (i, 16, 0) {
      int to = jump[i][v];
      if (to and !(st[u] >= st[to] and st[u] <= en[to]))
         v = to;
   }
   return p[v];
}
ll dist(int u, int v) {
	return l[u] + l[v] - 2*l[lca(u, v)];
}

struct DSU {
	vi p, r;
	DSU(int n):p(n),r(n){FOR(i, 0, n - 1)p[i] = i;}

	int get(int i) {
		if (p[i] != i)p[i] = get(p[i]);
		return p[i];
	}
	int connect(int i, int j) {
		int x = get(i), y = get(j);
		if (x == y) return 0;
		if (r[x] > r[y]) swap(x, y);
		p[x] = y;
		if (r[x] == r[y]) ++r[y];
		return 1;
	}
};

vector<ll> bfs(int u) {
	vector<ll> d(n + 1, 1e18);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	d[u] = 0;
	pq.emplace(0, u);
	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		if (d[it.S] < it.F) continue;
		for (auto itt : G[it.S]) {
			if (it.F + itt.S < d[itt.F]) {
				d[itt.F] = it.F + itt.S;
				pq.emplace(d[itt.F], itt.F);
			}
		}
	}
	return d;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int m; cin >> n >> m;
	DSU ds(n + 1);
	g.resize(n + 1);
	G.resize(n + 1);

	vector<pair<ii, int>> e;
	FOR (i, 0, m - 1) {
		int x, y, z; cin >> x >> y >> z;
		G[x].emplace_back(y, z);
		G[y].emplace_back(x, z);
		if (ds.connect(x, y)) {
			g[x].emplace_back(y, z);
			g[y].emplace_back(x, z);
		} else {
			e.push_back({{x, y}, z});
		}
	}

	pre();

	map<int, vector<ll>> mp;
	for (auto it : e) {
		mp[it.F.F] = bfs(it.F.F);
		mp[it.F.S] = bfs(it.F.S);
	}
	int q; cin >> q; while (q--) {
		int u, v; cin >> u >> v;
		ll ans = dist(u, v);
		for (const auto &it : mp) {
			ans = min(ans, dist(u, it.F) + it.S[v]);
		}
		cout << ans << "\n";
	}


	return 0;
}