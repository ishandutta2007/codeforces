#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 1 << 20, M = 1e7 + 7, mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}

int a[N];
int n, m, dfn[N], en[N], idt, dep[N], tag[N], up[N][20];
vi e[N];
void dfs(int x, int f) {
	dfn[x] = ++idt;
	for(int v : e[x]) if(v != f) {
		up[v][0] = x, dep[v] = dep[x] + 1, dfs(v, x);
	}
	en[x] = idt; 
}
int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	int t = dep[u] - dep[v];
	R(i, 19, 0) if(t >> i & 1) u = up[u][i];
	if(u == v) return u;
	R(i, 19, 0) if(up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
	return up[u][0];
}
int r[N];
 
struct fen {
	int a[N];
	void add(int x, int w) {
		for(; x < N; x += x & -x) 
			a[x] += w;
	}
	int qry(int x) {
		int ret = 0;
		for(; x; x -= x & -x) 
			ret += a[x];
		return ret;
	}
} A[30];

int ns[N];
vector < pair < int, int > > qwq[N];
vector < pair < pair < int, int >, int > > qry[N];

bool Prime[M];
int id[M], mn[M], p[N], tot;

int arr[N], cnt[N], tp;
void getfac(int x) {
	tp = 0;
	while(x > 1) {
		if(arr[tp] == mn[x]) cnt[tp] += 1;
		else arr[++tp] = mn[x], cnt[tp] = 1;
		x /= mn[x];
	}
}

int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	L(i, 2, M - 7) if(!Prime[i]) {
		++tot;
		id[i] = tot;
		p[tot] = i;
		L(j, 2, (M - 7) / i) Prime[i * j] = true;
		L(j, 1, (M - 7) / i) mn[i * j] = i;
	}
	cin >> n;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	L(i, 1, n) {
		cin >> a[i];
		getfac(a[i]);
		L(c, 1, tp) 
			qwq[id[arr[c]]].push_back({i, cnt[c]});
	}
	dfs(1, 0); 
	L(i, 1, 19) L(j, 1, n) up[j][i] = up[up[j][i - 1]][i - 1];
	cin >> m;
	L(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		int lc = lca(u, v);
		ns[i] = __gcd(a[lc], w);
		getfac(w);
		L(c, 1, tp) 
			qry[id[arr[c]]].push_back({make_pair(u, i), cnt[c]}), 
			qry[id[arr[c]]].push_back({make_pair(v, i), cnt[c]}), 
			qry[id[arr[c]]].push_back({make_pair(lc, i), -cnt[c]});
	}
	L(i, 1, tot) if(sz(qwq[i]) || sz(qry[i])) {
		int v = p[i], iv = qpow(p[i]), mx = 0;
		for(auto u : qwq[i]) {
			int i = u.first, v = u.second;
			mx = max(mx, v), A[v].add(dfn[i], 1), A[v].add(en[i] + 1, -1);
		}
		
		for(auto u : qry[i]) {
			int pos = u.first.first, ip = u.first.second;
			int ab = abs(u.second), sum = 0;
			L(i, 1, mx) 
				sum += min(ab, i) * A[i].qry(dfn[pos]);
//			cout << v << ' ' << pos << " : sum = " << sum << endl;
			if(u.second > 0) {
				ns[ip] = (ll) ns[ip] * qpow(v, sum) % mod;
			} else {
				ns[ip] = (ll) ns[ip] * qpow(iv, sum * 2) % mod;
			}
		}
		
		for(auto u : qwq[i]) {
			int i = u.first, v = u.second;
			mx = max(mx, v), A[v].add(dfn[i], -1), A[v].add(en[i] + 1, 1);
		}
	}
	L(i, 1, m) 
		cout << ns[i] << '\n';
	return 0;
}