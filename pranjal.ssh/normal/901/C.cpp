#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}


vector<vi> g;
vi vis, p, l;
vector<ii> seg;
void dfs(int u, int par) {
	p[u] = par;
	vis[u] = 1;
	for (int v : g[u]) if (v != par) {
		if (!vis[v]) l[v]=l[u]+1, dfs(v, u);
		else if (l[v] < l[u]) {
			seg.emplace_back(u, u);
			while (1) {
				u = p[u];
				seg.back().F = min(seg.back().F, u);
				seg.back().S = max(seg.back().S, u);
				if (u == v) break;
			}
		}
	}
}
vi st;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	g.resize(n); vis.resize(n), p.resize(n), l.resize(n);
	while (m--) {
		int u, v; cin >> u >> v; --u, --v;
		g[u].push_back(v), g[v].push_back(u);
	}
	FOR (i, 0, n - 1) if (!vis[i]) dfs(i, -1);

	st = vi(n, n-1);
	for (auto it :seg) {
		st[it.F] = min(st[it.F], it.S-1);
	}

	NFOR (i, n-2, 0) {
		st[i] = min(st[i], st[i+1]);
	}

	vector<ll> p(n);
	FOR (i, 0, n-1) {
		p[i] = st[i];
		if (i) p[i] += p[i-1];
	}

	auto get = [&](int l, int r) {
		if (l > r) return 0LL;
		if (l == 0) return p[r];
		return p[r]-p[l-1];
	};

	int q; cin >> q; while (q--) {
		int l, r; cin >> l >> r;
		--l, --r;
		int it = upper_bound(st.begin()+l, st.begin()+r+1, r) - st.begin();
		int R = r - it + 1;
		cout << get(l, it-1) + R*1LL*r - (r-1LL)*r/2 + (l-2LL)*(l-1)/2 << "\n";
	}

	return 0;
}