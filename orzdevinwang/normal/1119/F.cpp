#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 5e5 + 7;
const ll linf = 1e15;
mt19937 orz(time(0) ^ clock());
int rt[N], ch[N][2], key[N], val[N], siz[N], tot; 
ll sum[N];
int newn (int w) { ++tot, val[tot] = w, sum[tot] = w, key[tot] = orz(), siz[tot] = 1; return tot; }
void upd(int x) {
	siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
	sum[x] = sum[ch[x][0]] + sum[ch[x][1]] + val[x];
}
int merge(int x, int y) {
	if(!x || !y) return x | y;
	if(key[x] < key[y]) return ch[x][1] = merge(ch[x][1], y), upd(x), x;
	else return ch[y][0] = merge(x, ch[y][0]), upd(y), y;
}
void split(int x, int w, int &a, int &b) {
	if(!x) return a = b = 0, void();
	if(val[x] <= w) a = x, split(ch[a][1], w, ch[a][1], b), upd(a);
	else b = x, split(ch[b][0], w, a, ch[b][0]), upd(b);
}
void splitk(int x, int w, int &a, int &b) {
	if(!x) return a = b = 0, void();
	if(siz[ch[x][0]] + 1 <= w) a = x, splitk(ch[a][1], w - siz[ch[x][0]] - 1, ch[a][1], b), upd(a);
	else b = x, splitk(ch[b][0], w, a, ch[b][0]), upd(b);
}

void ins (int x, int w) {
	int u = newn(w), spx, spy;
	split(rt[x], w, spx, spy), rt[x] = merge(merge(spx, u), spy);
//	cout << "modify " << x << " += " << w << "\n";
} 

ll getk (int x, int k) {
	if(k <= 0) return 0;
	if(k > siz[rt[x]]) return linf;
	int spx, spy; 
	splitk(rt[x], k, spx, spy);
	ll res = sum[spx];
	rt[x] = merge(spx, spy);
//	cout << "query " << x << " " << k << ", ns = " << res << "\n";
	return res;
}

int n, m, deg[N];
struct pr {
	int x, deg;
} s[N];
int eid = 1, ev[N], ew[N];
set < int > e[N];
void eadd(int u, int v, int w) {
	++eid, ev[eid] = v, ew[eid] = w, e[u].insert(eid), deg[u]++;
}

ll f[N], g[N]; 
// g : (father -> x) 
// f : no (father -> x)
int k, vis[N]; 
void DP(int x, int fa) {
	vis[x] = k, f[x] = g[x] = linf;
	vector < ll > tmp;
	ll sum = 0;
	for(const int &i : e[x]) if(ev[i] != fa) {
		int v = ev[i], w = ew[i];
		DP(v, x), g[v] += w, f[v] = min(f[v], g[v]);
		sum += f[v], tmp.push_back(g[v] - f[v]);
	}
	sort(tmp.begin(), tmp.end());
	int delt = deg[x] - k;
	ll now = 0;
	L(i, 0, sz(tmp)) {
		f[x] = min(f[x], now + getk(x, delt - i));
		g[x] = min(g[x], now + getk(x, delt - i - 1));
		if(i != sz(tmp)) now += tmp[i];
	}
	f[x] += sum, g[x] += sum;
//	cout << x << " : " << f[x] << " " << g[x] << "\n"; 
} 

void Delete(int x) {
	for(const int &i : e[x]) e[ev[i]].erase(i ^ 1), ins(ev[i], ew[i]); 
	e[x].clear();
}

vector < ll > minimum_closure_costs(int N, vi U, vi V, vi W) {
	vector < ll > ns; 
	n = N, ns.resize(n); 
	L(i, 1, n) s[i].deg = 0, s[i].x = i;
	L(i, 0, n - 2) ++U[i], ++V[i], s[U[i]].deg++, s[V[i]].deg++, eadd(U[i], V[i], W[i]), eadd(V[i], U[i], W[i]);
	sort(s + 1, s + n + 1, [&] (pr a, pr b) {
		return a.deg < b.deg;
	});
	int p = 1;
	memset(vis, -1, sizeof(vis));
	L(a, 0, n - 1) {
		k = a;
		while(p <= n && s[p].deg < a) Delete(s[p].x), ++p;
		L(i, p, n) if(vis[s[i].x] != a) DP(s[i].x, -1), ns[a] += f[s[i].x];
	}
	return ns;
}

int main() {
	int n;
	cin >> n;
	vi su, sv, sw;
	L(i, 1, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		su.push_back(u);
		sv.push_back(v);
		sw.push_back(w);
	}
	vector < ll > ns =  minimum_closure_costs(n, su, sv, sw);
	L(i, 0, n - 1) cout << ns[i] << " ";
	cout << "\n";
	return 0;
}