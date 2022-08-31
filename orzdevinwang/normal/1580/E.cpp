#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define i128 __int128
using namespace std;
const int N = 6e5 + 7;
int n, m, q;
ll cw[N];
int ehd[N], ev[N], enx[N], ew[N], eid;
int ord[N], mp[N], tp, Fa[N];
void eadd (int u, int v, int w) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid;
} 
ll dis[N], w[N];
bool vis[N];
int pr[N], No[N], tot;
vi S[N], cno[N];
int all[N];
void Dij () {
	memset(dis, 0x3f, sizeof(dis));
	priority_queue < pair < ll, int > > q;
	q.push ({0, 1}), dis[1] = 0;
	while (!q.empty()) {
		int u = q.top ().second;
		q.pop();
		if(vis[u]) continue;
		++tp, ord[tp] = u, mp[u] = tp;
		vis[u] = true;
		for (int i = ehd[u]; i; i = enx[i]) 
			if(dis[ev[i]] > dis[u] + ew[i]) 
				dis[ev[i]] = dis[u] + ew[i], q.push ({-dis[ev[i]], ev[i]});
	}
	Fa[1] = -1;
	L(u, 2, n) {
		for (int i = ehd[u]; i; i = enx[i]) if(dis[ev[i]] + ew[i] == dis[u]) {
			if(!Fa[u]) Fa[u] = ev[i];
			else Fa[u] = -1;
		}
		if(Fa[u] == 1) Fa[u] = 0;
	}
	int lst = 0;
	L(u, 1, n) {
		w[u] = cw[ord[u]];
		if(dis[ord[u]] != dis[ord[u - 1]]) lst = u - 1;
		if(Fa[ord[u]] != -1) ++tot, pr[tot] = lst, No[tot] = mp[Fa[ord[u]]], all[pr[tot]] += 1;
	}
	L(i, 1, n + 2) all[i] += all[i - 1]; 
	w[0] = 1e18;
	L(i, 1, tot) S[pr[i]].push_back(No[i]), cno[No[i]].push_back(pr[i]);
	L(i, 0, n) sort(cno[i].begin(), cno[i].end());
}

struct Data {
	int mn1, mn2;
	Data (int m1 = 0, int m2 = 0) { mn1 = m1, mn2 = m2; }
	void insert (int i) {
		if(w[mn1] > w[i]) mn2 = mn1, mn1 = i;
		else if(w[mn2] > w[i]) mn2 = i;
	}
	friend Data operator + (Data a, Data o) {
		Data ns = a;
		ns.insert(o.mn1);
		ns.insert(o.mn2);
		return ns;
	}
};

Data s[1 << 20];
int Sum;
inline void upd (int x) {
	s[x] = s[x << 1] + s[x << 1 | 1];
}
inline void build (int id, int l, int r) {
	if(l == r) return s[id] = Data (l, 0), void ();
	int mid = (l + r) >> 1;
	build (id << 1, l, mid), build (id << 1 | 1, mid + 1, r);
	upd (id);
}
inline void mdf (int id, int L, int R, int p) {
	if(L == R) return ;
	int mid = (L + R) >> 1;
	if(p <= mid) mdf (id << 1, L, mid, p);
	else mdf (id << 1 | 1, mid + 1, R, p);
	upd (id);
}
inline Data qry1(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return s[id];
	int mid = (L + R) >> 1;
	Data ret;
	if(l > mid) return qry1(id << 1 | 1, mid + 1, R, l, r);
	if(r <= mid) return qry1(id << 1, L, mid, l, r);
	return qry1(id << 1, L, mid, l, r) + qry1(id << 1 | 1, mid + 1, R, l, r);
}
inline int gnx (int id, int L, int R, int l, int r, ll W) {
	if(w[s[id].mn1] > W) return -1;
	if(L == R) return L;
	int mid = (L + R) >> 1, ret ;
	if(l <= mid && (~(ret = gnx(id << 1, L, mid, l, r, W)))) return ret;
	if(r > mid && (~(ret = gnx(id << 1 | 1, mid + 1, R, l, r, W)))) return ret;
	return -1;
} 

i128 ns;
inline int get (int l, int r, ll x) { //  [l,r]  <= w  
	l = max(l, 1);
	if(l > r) return -1;
	return gnx (1, 1, n, l, r, x);
}
i128 getv (int x) {
	int lst = get (1, x - 1, w[x]), rst = get (x + 1, n, w[x] - 1);
	if(rst == -1) rst = n + 1; 
	if(lst != -1 && get (lst + 1, x - 1, w[x]) != -1) return 0 ;
	int cnt = 0;
	if(lst != -1) {
		cnt += lower_bound(cno[lst].begin(), cno[lst].end(), rst) - 
			lower_bound(cno[lst].begin(), cno[lst].end(), x);
	}
	else {
		int cst = get (rst + 1, n, w[x] - 1);
		if(cst == -1) cst = n + 1;
		cnt = all[rst - 1] - all[x - 1];
		cnt -= lower_bound(cno[x].begin(), cno[x].end(), rst) - 
			lower_bound(cno[x].begin(), cno[x].end(), x);
			
		cnt += lower_bound(cno[rst].begin(), cno[rst].end(), cst) - 
			lower_bound(cno[rst].begin(), cno[rst].end(), rst);
	} 
	return (i128) cnt * w[x];
}

void Dec (int x, int k) {
	Data M ;
	if(x > 1) M = qry1(1, 1, n, 1, x - 1);
	
	vi S;
	
	if(M.mn1) S.push_back (M.mn1);
	if(M.mn2) S.push_back (M.mn2);
	S.push_back (x); 
	
	M.insert(x);
	
	int z = x + 1;
	while (z <= n) {
		if(w[M.mn2] < w[x] - k) break;
		int i = get(z, n, min(w[M.mn2], w[x] - 1));
		if(i == -1) break;
		if(w[x] - k <= w[i]) S.push_back(i);
		M.insert(i);
		z = i + 1;
	}
	
	Sum += sz(S);
	if(Sum > 1.8e6) assert (0);
	
	for (const int &t : S) ns -= getv(t);
	w[x] -= k, mdf (1, 1, n, x); 
	for (const int &t : S) ns += getv(t);
}
inline i128 query () {
	L(i, 1, n) ns += getv(i); 
	return ns;
}
int sx[N], sk[N];
i128 nsw[N];
void prt (i128 x) {
	if(x >= 10) prt(x / 10);
	cout << ((int) (x % 10));
}
int main () {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	L(i, 1, n) cin >> cw[i];
	L(i, 1, m) {
		int u, v, d;
		cin >> u >> v >> d;
		eadd (u, v, d);
		eadd (v, u, d);
	}
	Dij ();
	L(i, 1, q) cin >> sx[i] >> sk[i], sx[i] = mp[sx[i]];
	L(i, 1, q) w[sx[i]] += sk[i];
	build (1, 1, n);
	nsw[q + 1] = query();
	R(i, q, 1) Dec(sx[i], sk[i]), nsw[i] = ns;
	L(i, 1, q + 1) prt(nsw[i]), cout << '\n';
	return 0;
}