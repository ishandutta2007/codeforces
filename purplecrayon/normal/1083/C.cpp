#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;
 
template<class T> struct RMQ { //min range query (default)
	vector<vector<T>> st;
	vector<int> log;
	T combine(T a, T b) {return min(a, b);}
	void build(int n, vector<T>& a) {
		log = vector<int>(n + 1);
		for (int i = 2; i <= n; ++i) log[i] = log[i >> 1] + 1;
		int k = log[n];
		st = vector<vector<T>>(n, vector<T>(k + 1));
		for (int i = 0; i < n; ++i) st[i][0] = a[i];
		for (int j = 1; j <= k; ++j) for (int i = 0; i + (1 << j) - 1 < n; ++i)
			st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j-1]);
	}
	T qry(int l, int r) {
		int k = log[r - l + 1];
		return combine(st[l][k], st[r - (1 << k) + 1][k]);
	}
};

struct LCA {
	int n = 0, timer = 0;
	vector<vector<int>> adj;
	vector<int> oc; // first occurence of each node
	vector<int> dep;
	vector<int> euler;
	RMQ<pair<int, int>> rmq; // <dep, node index>

	void init(vector<vector<int>> _adj) {
		adj = _adj;
		n = adj.size();
		oc.resize(n);
		dep.resize(n);
		dfs();
		int k = euler.size();
		vector<pair<int, int>> pairs;
		for (int u : euler) pairs.emplace_back(dep[u], u);
		rmq.build(k, pairs);
	}

	void dfs(int u = 0, int p = -1) {
		oc[u] = timer++;
		euler.push_back(u);
		for (int v : adj[u]) if (v != p) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
			euler.push_back(u);
			++timer;
		}
	}

	int lca(int a, int b) {
		a = oc[a], b = oc[b];
		if (a > b) swap(a, b);
		return rmq.qry(a, b).second;
	}

	int dist(int a, int b) {
		return dep[a] + dep[b] - 2 * dep[lca(a, b)];
	}
} lc;

int n, a[MAXN], b[MAXN];
ar<int, 2> t[4*MAXN];

#define dist lc.dist
ar<int, 2> mrg(ar<int, 2> a, int b) {
    if (a[0] == -1 || a[1] == -1 || b == -1) return {-1, -1};

    for (ar<int, 3> c : {ar<int, 3>{a[0], a[1], b}, ar<int, 3>{a[1], b, a[0]}, ar<int, 3>{b, a[0], a[1]}}) {
        if (dist(c[0], c[1]) == dist(c[0], c[2]) + dist(c[2], c[1])) {
            return {c[0], c[1]};
        }
    }

    return {-1, -1};
}
ar<int, 2> mrg(ar<int, 2> a, ar<int, 2> b) {
    return mrg(mrg(a, b[0]), b[1]);
}
void bld(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {b[tl], b[tl]};
    } else {
        int tm=(tl+tr)/2;
        bld(2*v, tl, tm), bld(2*v+1, tm+1, tr);
        t[v] = mrg(t[2*v], t[2*v+1]);
    }
    //cerr << tl << ' ' << tr << ' ' << t[v][0] << ' ' << t[v][1] << endl;
}
void upd(int v, int tl, int tr, int pos, int val) {
    if (tr < pos || tl > pos) return;
    if (tl == tr) {
        //cerr << "h: " << pos << ' ' << val << endl;
        t[v] = {val, val};
        return;
    }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, pos, val), upd(2*v+1, tm+1, tr, pos, val);
    t[v] = mrg(t[2*v], t[2*v+1]);
}
ar<int, 3> qry(int v, int tl, int tr, ar<int, 3> prv) {
    if (tl == tr) {
        ar<int, 2> cv = mrg({prv[0], prv[1]}, t[v]);
        if (cv[0] == -1 || cv[1] == -1) {
            return prv;
        } else {
            return {cv[0], cv[1], tl};
        }
    }
    int tm=(tl+tr)/2;
    ar<int, 2> cv = mrg({prv[0], prv[1]}, t[2*v]);
    if (cv[0] != -1 && cv[1] != -1) {
        return qry(2*v+1, tm+1, tr, {cv[0], cv[1], max(tm, prv[2])});
    }
    return qry(2*v, tl, tm, prv);
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], b[a[i]] = i;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p, --p;
        adj[p].push_back(i), adj[i].push_back(p);
    }
    lc.init(adj);
    bld(1, 0, n-1);
    
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v, --u, --v;
            int a1=a[u], a2=a[v];
            upd(1, 0, n-1, a1, v), upd(1, 0, n-1, a2, u);
            swap(a[u], a[v]), swap(b[a1], b[a2]);
        } else {
            cout << qry(1, 0, n-1, {b[0], b[0], 0})[2]+1 << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    // cin >> t_c;
    while (t_c--) solve();
}