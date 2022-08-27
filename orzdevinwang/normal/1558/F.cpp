#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = (1 << 19), inf = 1919810;
int n, a[N], mp[N];
bool vis[N];
int res, nt;
int sum[N], ns[N];
void upd (int x) {
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
	ns[x] = max(ns[x << 1] + sum[x << 1 | 1], ns[x << 1 | 1]);
}
void build (int x, int l, int r) {
	if(l == r) 
		return ns[x] = - inf + l, sum[x] = 0, void ();
	int mid = (l + r) >> 1;
	build (x << 1, l, mid);
	build (x << 1 | 1, mid + 1, r);
	upd (x);
}
void add1 (int x, int L, int R, int p, int w) {
	if (L == R) return ns[x] += w, void ();
	int mid = (L + R) >> 1;
	if(p <= mid) add1 (x << 1, L, mid, p, w);
	else add1 (x << 1 | 1, mid + 1, R, p, w);
	upd (x);
}
void add2 (int x, int L, int R, int p, int w) {
	if (L == R) return sum[x] += w, ns[x] += w, void ();
	int mid = (L + R) >> 1;
	if(p <= mid) add2 (x << 1, L, mid, p, w);
	else add2 (x << 1 | 1, mid + 1, R, p, w);
	upd (x);
}
int chk () {
	int w = 0, res = 0;
	R(i, n, nt) if(vis[i]) res += 1, w = max(w, res * 2 + i);
	return w;
}
void insert (int x) {
	vis[x] = true; 
	add1 (1, 1, n, x, inf);
	add2 (1, 1, n, x, 2); 
}
void Main () {
	res = 0;
	cin >> n;
	L(i, 1, n) cin >> a[i], mp[a[i]] = i;
	bool ok = true;
	L(i, 1, n - 1) ok &= a[i] < a[i + 1];
	if(ok) return cout << 0 << "\n", void();
	nt = 1; 
	build (1, 1, n);
	L(i, 1, n) {
		int v = mp[i] - ! (mp[i] & 1);
		if(vis[v]) insert(v & 1 ? v + 1 : v - 1);
		else insert (v);
		while (nt <= n && vis[nt]) add1 (1, 1, n, nt, -inf), ++nt; 
//		res = max (res, chk () - i - 2);
		res = max (res, ns[1] - i - 2);
//		cout << "is " << ns[1] << "\n";
	}
	cout << res + 1 << "\n";
	L(i, 1, n) vis[i] = false;
}
int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}