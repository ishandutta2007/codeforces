#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 5e5 + 7, M = (1 << 20), cm = 1 << 19;
ll wl[M];
ll query (int l, int r) {
	ll ns = 1e18;
	for (l += cm - 1, r += cm + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
		if(~l & 1) ns = min(ns, wl[l ^ 1]); 
		if(r & 1) ns = min(ns, wl[r ^ 1]);
	}
	return ns;
}
void modify (int x, ll w) {
	for (x += cm, wl[x] = w, x >>= 1; x; x >>= 1) wl[x] = min(wl[x << 1], wl[x << 1 | 1]);
}
vi e[N], qry[N];
int n, m, p[N], ds[N], deg[N];
int fn, rt, rtmax, siz[N];
int qv[N], ql[N], qr[N], arr[N], atot;
bool vis[N];
ll len[N], ns[N];
void findrt(int x, int fa) {
	int maxn = 0;
	siz[x] = 1;
	for(const int &v : e[x]) if(v ^ fa && !vis[v]) findrt(v, x), siz[x] += siz[v], maxn = max(maxn, siz[v]);
	maxn = max(maxn, fn - siz[x]);
	if(maxn < rtmax) rt = x, rtmax = maxn;
}
void work(int x, int fa) {
	arr[++atot] = x;
	if(!deg[x]) modify(x, len[x]); //, cout << x << " add " << len[x] << '\n';
	for(const int &v : e[x]) 
		if(v ^ fa && !vis[v]) len[v] = len[x] + (p[x] == v ? ds[x] : ds[v]), work (v, x);
}
void divide(int x) {
	rtmax = 1e9, findrt(x, -1);
	atot = 0, len[rt] = 0, work (rt, -1);
//	cout << "rt = " << rt << " : " << len[1] << ' ' << query (1, n) << "\n";
	L(i, 1, atot) for (const int &t : qry[arr[i]]) ns[t] = min(ns[t], query (ql[t], qr[t]) + len[arr[i]]);
	L(i, 1, atot) if(!deg[arr[i]]) modify(arr[i], 1e18);
	vis[rt] = 1;
	int srt = rt;
	for(const int &v : e[srt]) if(!vis[v]) fn = siz[v], divide(v);
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(wl, 0x3f, sizeof(wl));
	cin >> n >> m;
	L(i, 2, n) cin >> p[i] >> ds[i], deg[p[i]] += 1, e[p[i]].push_back(i), e[i].push_back(p[i]);
	L(i, 1, m) cin >> qv[i] >> ql[i] >> qr[i], ns[i] = 1e18, qry[qv[i]].push_back(i);
	fn = n, divide (1);
	L(i, 1, m) cout << ns[i] << "\n";
	return 0;
}