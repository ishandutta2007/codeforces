#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
using namespace std;
const int N = 1e6 + 7;


mt19937_64 orz(time(0) ^ clock());
int key[N], siz[N], ch[N][2], tot;
ll w[N], tag[N];
void upd(int x) {
	siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
}
void adk(int x, ll z) {
	if(x) tag[x] += z, w[x] += z;
}
void push(int x) {
	if(tag[x]) adk(ch[x][0], tag[x]), adk(ch[x][1], tag[x]), tag[x] = 0;
}
void split(int now, ll k, int &x, int &y) {
	if(!now) return x = y = 0, void ();
	push(now);
	if(w[now] <= k) x = now, split(ch[x][1], k, ch[x][1], y), upd(x);
	else y = now, split(ch[y][0], k, x, ch[y][0]), upd(y);
} 

void xsplit(int now, int k, int &x, int &y) {
	if(!now) return x = y = 0, void ();
	push(now);
	if(k > siz[ch[now][0]]) x = now, xsplit(ch[x][1], k - siz[ch[now][0]] - 1, ch[x][1], y), upd(x);
	else y = now, xsplit(ch[y][0], k, x, ch[y][0]), upd(y);
} 

int merge(int x, int y) {
	if(!x || !y) return x | y;
	push(x), push(y);
	if(key[x] < key[y]) return ch[x][1] = merge(ch[x][1], y), upd(x), x;
	else return ch[y][0] = merge(x, ch[y][0]), upd(y), y;
}

int rt, spx, spy, spz;

ll Kth(int x) { 
	int spx, spy, spz;
	ll rns;
	xsplit(rt, x, spx, spz);
	assert(siz[spx] == x);
	xsplit(spx, x - 1, spx, spy), rns = w[spy];
	rt = merge(merge(spx, spy), spz);
	return rns;
} 

int n, q;
ll d;
struct qry {
	int k, m, id;
} f[N]; 
ll ans[N];

ll a[N], wa[N], qt, cp, rd, kr;
char s[N];

ll b[N];

void rp() {
	while(cp < n && kr >= a[cp + 1]) ++cp, ++kr;
	xsplit(rt, 1, spx, spy), w[spx] = kr;
	xsplit(spy, cp - 1, spy, spz);
//	cout << "spx : ", dfs(spx), cout << endl;
//	cout << "spy : ", dfs(spy), cout << endl;
	rt = merge(merge(spy, spx), spz);
//	dfs(rt), cout << endl;
}

void work(ll x) {
	rd = d + cp - 1;
	ll pd = (x - 1) / cp;
	ll pre = x - pd * cp; // * 
	xsplit(rt, cp, spx, spz);
	adk(spx, pd * rd);
	xsplit(spx, pre, spx, spy);
	adk(spx, rd);
	rt = merge(merge(spy, spx), spz);
}

void wk(int x) {
	if(!x) return ;
	ll l = 1, r = x, ns = -1;
	while(l <= r) {
		ll mid = (l + r) >> 1;
		ll op = (mid - 1) / cp;
		ll val = Kth(mid - op * cp) + (d + cp - 1) * (op + 1);
		if(cp < n && val >= a[cp + 1]) {
			ns = mid, kr = val, r = mid - 1;
		} else l = mid + 1;
	} 
	if(ns == -1) {
		work(x);
	} else {
		work(ns - 1);
		rp();
		x -= ns;
		wk(x);
	}
}

int query(ll x) {
	int spx, spy, rns;
	split(rt, x, spx, spy);
	rns = siz[spx];
	rt = merge(spx, spy);
	return rns;
}

int main() {
//	return system("fc my.out ans.out"), 0;
//	freopen("data.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> d >> q;
	L(i, 1, n) {
		cin >> a[i];
	}
	
	cin >> (s + 1);
	
	int xn = 0;
	L(i, 1, n) 
		if(s[i] == '1') {
			a[++xn] = a[i] - qt;
		} else {
			wa[++qt] = a[i];	
		}
	n = xn;
	
	L(i, 1, n) {
		w[i] = a[i], key[i] = orz(), siz[i] = 1, rt = merge(rt, i);	
	} 
//	dfs(rt), cout << "," << endl;
	
	L(i, 1, q) {
		cin >> f[i].k >> f[i].m, f[i].id = i;
	}
	sort(f + 1, f + q + 1, [&] (qry a, qry b) {
		return a.k < b.k;
	});
	cp = 1;
	int curk = 0;
	L(i, 1, q) {
		wk(f[i].k - curk);
		curk = f[i].k;
		ll l = 1, r = 2e18, ns = -1;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			int zs = upper_bound(wa + 1, wa + qt + 1, mid) - wa - 1;
			ll qz = mid - zs;
			if(zs + query(qz) < f[i].m) ns = mid, l = mid + 1;
			else r = mid - 1;
		}
		ans[f[i].id] = ns + 1;
	}
	L(i, 1, q) cout << ans[i] << '\n';
	return 0;
}