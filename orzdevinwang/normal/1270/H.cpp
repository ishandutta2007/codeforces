#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 21, mx = 1e6;
int n, q, tag[N], mn[N], cnt[N], a[N];
void upd (int x) {
	mn[x] = min(mn[x << 1], mn[x << 1 | 1]), cnt[x] = 0;
	if(mn[x] == mn[x << 1]) cnt[x] += cnt[x << 1];
	if(mn[x] == mn[x << 1 | 1]) cnt[x] += cnt[x << 1 | 1];	
}
void AD (int x, int w) {
	tag[x] += w, mn[x] += w;
}
void pushdown (int x) {
	if(tag[x]) AD (x << 1, tag[x]), AD (x << 1 | 1, tag[x]), tag[x] = 0;
}
void build (int x, int L, int R) {
	if(L == R) return cnt[x] = 1, void ();
	int mid = (L + R) >> 1;
	build (x << 1, L, mid), build (x << 1 | 1, mid + 1, R), upd (x);
}
void add (int x, int L, int R, int l, int r, int w) {
	if(l <= L && R <= r) return AD (x, w), void ();
	pushdown(x);
	int mid = (L + R) >> 1;	
	if(l <= mid) add (x << 1, L, mid, l, r, w);
	if(r > mid) add (x << 1 | 1, mid + 1, R, l, r, w);
	upd (x); 
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	build(1, 1, mx);
	L(i, 1, n) cin >> a[i], add(1, 1, mx, a[i], a[i], -1);
	L(i, 1, n - 1) if(a[i] < a[i + 1]) add (1, 1, mx, a[i], a[i + 1] - 1, 1);
	while (q--) {
		int p, x;
		cin >> p >> x;
		add (1, 1, mx, a[p], a[p], 1);
		if(p < n && a[p] < a[p + 1]) add (1, 1, mx, a[p], a[p + 1] - 1, -1);
		if(p > 1 && a[p - 1] < a[p]) add (1, 1, mx, a[p - 1], a[p] - 1, -1);
		a[p] = x;
		add (1, 1, mx, a[p], a[p], -1);
		if(p < n && a[p] < a[p + 1]) add (1, 1, mx, a[p], a[p + 1] - 1, 1);
		if(p > 1 && a[p - 1] < a[p]) add (1, 1, mx, a[p - 1], a[p] - 1, 1);
		cout << cnt[1] << '\n';
	}
	return 0;
}