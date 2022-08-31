#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 20);
int n, m, a[N], xm[N];
multiset < int > st[N];
int mx[N], lmx[N], rmx[N];
int mnc[N], ns[N], tag[N];
void upd (int x) {
	mnc[x] = min(mnc[x << 1], mnc[x << 1 | 1]);
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
	lmx[x] = lmx[x << 1], rmx[x] = rmx[x << 1 | 1];
	if(mnc[x] == mnc[x << 1] && mnc[x] == mnc[x << 1 | 1]) {
		ns[x] = ns[x << 1] + ns[x << 1 | 1] + max(rmx[x << 1], lmx[x << 1 | 1]);
	} else if(mnc[x] == mnc[x << 1]) {
		ns[x] = ns[x << 1], rmx[x] = max(rmx[x << 1], mx[x << 1 | 1]);
	} else if(mnc[x] == mnc[x << 1 | 1]) {
		ns[x] = ns[x << 1 | 1], lmx[x] = max(mx[x << 1], lmx[x << 1 | 1]);
	} else assert (0);
}
void AD (int x, int w) { mnc[x] += w, tag[x] += w; } 
void pushdown (int x) {
	if(tag[x]) AD(x << 1, tag[x]), AD(x << 1 | 1, tag[x]), tag[x] = 0;
}
void build (int x, int L, int R) {
	if(L == R) return lmx[x] = xm[L], rmx[x] = xm[L + 1], mx[x] = max(lmx[x], rmx[x]), void();
	int mid = (L + R) >> 1;
	build (x << 1, L, mid);
	build (x << 1 | 1, mid + 1, R);
	upd (x);
}
void add (int x, int L, int R, int l, int r, int w) {
	if(l <= L && R <= r) return AD(x, w);
	pushdown (x);
	int mid = (L + R) >> 1;
	if(l <= mid) add (x << 1, L, mid, l, r, w);
	if(r > mid) add (x << 1 | 1, mid + 1, R, l, r, w);
	upd (x);
}
void mark (int x, int L, int R, int p) {
	if(L == R) return lmx[x] = xm[L], rmx[x] = xm[L + 1], mx[x] = max(lmx[x], rmx[x]), void();
	pushdown(x);
	int mid = (L + R) >> 1;
	if(p <= mid) mark (x << 1, L, mid, p);
	else mark (x << 1 | 1, mid + 1, R, p);
	upd (x);
}
void ins (int x) {
	if(!sz(st[x])) return ;
	int c = * st[x].begin();
	if(xm[c]) assert (0);
	xm[c] = sz(st[x]);
	if(c < n) mark (1, 1, n - 1, c);
	if(c > 1) mark (1, 1, n - 1, c - 1);
	if(sz(st[x]) > 1) add (1, 1, n - 1, * st[x].begin(), * st[x].rbegin() - 1, 1);
}
void del (int x) {
	if(!sz(st[x])) return ; 
	int c = * st[x].begin();
	xm[c] = 0;
	if(c < n) mark (1, 1, n - 1, c);
	if(c > 1) mark (1, 1, n - 1, c - 1);
	if(sz(st[x]) > 1) add (1, 1, n - 1, * st[x].begin(), * st[x].rbegin() - 1, -1);
}
inline int query () {
	if(mnc[1] > 0) return n - mx[1];
	return n - ns[1] - lmx[1] - rmx[1];
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if(n == 1) {
		L(i, 0, m) cout << 0 << '\n';
		return 0;
	}
	L(i, 1, n) cin >> a[i], st[a[i]].insert(i);
	build (1, 1, n - 1);
	L(i, 1, N - 1) if(sz(st[i])) ins (i);
	cout << query () << '\n';
	while (m--) {
		int x, y;
		cin >> x >> y;
		if(a[x] != y) {
			del (a[x]), del (y);
			st[a[x]].erase(x), st[y].insert (x);
			ins (a[x]), ins (y);
			a[x] = y;
		}
		cout << query () << '\n';
	} 
	return 0;
}