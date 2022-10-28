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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}


vi p, st, en, l;
vector<vi> jump;
int n;
vector<vi> g;

void dfs(int u) {
	static int ctr = 0;
	st[u] = ++ctr;
	for (auto it : g[u]) {
		if (it == p[u]) continue;
		p[it] = u;
		l[it] = l[u] + 1;
		dfs(it);
	}
	en[u] = ctr;
}

void pre() {
	jump = vector<vi>(20, vi(n + 1));
	l = st = en = p = vi(n + 1);
	dfs(1);
	FOR (i, 1, n) jump[0][i] = p[i];
	FOR (i, 1, 19) {
		FOR (j, 1, n) {
			jump[i][j] = jump[i - 1][jump[i - 1][j]];
		}
	}
}
inline bool insub(int a, int c) {
	return st[c] >= st[a] and st[c] <= en[a];
}
int lca(int u, int v) {
	if (st[u] >= st[v] and st[u] <= en[v]) return v;
	NFOR (i, 19, 0) {
		int to = jump[i][v];
		if (to and !(st[u] >= st[to] and st[u] <= en[to]))
			v = to;
	}
	return p[v];
}

int lca(int u, int v, int root) {
	int x = lca(u, v);
	if (insub(root, u) and insub(root, v)) return x;
	if (insub(root, u) xor insub(root, v)) return root;
	if (insub(x, root)) {
		NFOR (i, 19, 0) {
			int to = jump[i][root];
			if (to and !(insub(to, u) or insub(to, v)))
				root = to;
		}
		return p[root];
	}

	return x;
}
template<typename T>
struct BIT1	// Point update,query
{
	vector<T> t;int n;BIT1(){n=0;}
	BIT1(int sz){ n=sz; t=vector<T>(sz+1,0);}
	void upd(int i, T val){ while(i<=n) t[i]+=val, i+=i&-i;}
	T qry(int i){T ans=0; while(i>0) ans+=t[i],i-=i&-i; return ans;}
};
ll off = 0;
template<typename T>
struct BIT2	// Range update,query
{
	int n;vector<T> t;BIT1<T> y,z;
	BIT2(int sz) : n(sz), t(sz+1), y(sz), z(sz) {}
	void updr(int l, int r, T val){y.upd(l,val); y.upd(r+1,-1*val); z.upd(l,l*val); z.upd(r+1,-1*(r+1)*val);}
	T qryr(int l,int r){return (r+1)*(y.qry(r)-y.qry(l-1)) + (r-l+1)*(y.qry(l-1)) - (z.qry(r)-z.qry(l-1)) + off*(r-l+1);}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int q; cin >> n >> q;
	g.resize(n + 1);
	vector<ll> a(n + 1); FOR (i, 1, n) cin >> a[i];

	FOR (i, 1, n - 1) {
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}



	pre();
	BIT2<ll> bt(n + 1);
	int root = 1;

	FOR (i, 1, n) sort(all(g[i]), [](int x, int y) {
		return st[x] < st[y];
	});

	FOR (i, 1, n) {
		bt.updr(st[i], st[i], a[i]);
	}

	
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int v; cin >> v;
			root = v;
		} else if (t == 2) {
			int u, v, x; cin >> u >> v >> x;
			int w = lca(u, v, root);
			assert(w);
			if (w == root) {
				off += x;
			} else if (insub(w, root)) {
				// assert(sz(g[w]) > 1);
				int lo = 1, hi = sz(g[w])-1;
				if (w == 1) lo = 0;
				while (lo < hi) {
					int mid = (lo + hi + 1) >> 1;
					if (st[g[w][mid]] > st[root]) hi = mid - 1;
					else lo = mid;
				}
				w = g[w][lo];
				off += x;
				// pr(w);
				// assert(w);
				bt.updr(st[w], en[w], -x);
			} else {
				// assert(w);
				bt.updr(st[w], en[w], x);
			}
		} else {
			int w; cin >> w;
			if (w == root) {
				cout << bt.qryr(1, n) << "\n";
			} else if (insub(w, root)) {
				int lo = 1, hi = sz(g[w])-1;
				if (w == 1) lo = 0;
				assert(lo <= hi);
				while (lo < hi) {
					int mid = (lo + hi + 1) >> 1;
					if (st[g[w][mid]] > st[root]) hi = mid - 1;
					else lo = mid;
				}
				w = g[w][lo];
				// pr(w);
				assert(w);
				cout << bt.qryr(1, n) - bt.qryr(st[w], en[w]) << "\n";
			} else {
				// pr(st[w], en[w]);
				// assert(w);
				cout << bt.qryr(st[w], en[w]) << "\n";
			}
		}
	}



	return 0;
}