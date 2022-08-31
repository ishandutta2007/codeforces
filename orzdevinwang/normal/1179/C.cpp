#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 21, Mx = 1e6, mod = 998244353;
int n, m, q, a[N], b[N];
int sum[N], mx[N];
void upd (int x) {
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
	mx[x] = max(mx[x << 1 | 1], mx[x << 1] + sum[x << 1 | 1]);
}
void add (int x, int L, int R, int p, int w) {
	if(L == R) return sum[x] += w, mx[x] = sum[x], void ();
	int mid = (L + R) >> 1;
	if(p <= mid) add (x << 1, L, mid, p, w);
	else add (x << 1 | 1, mid + 1, R, p, w);
	upd (x);
}
int query (int x, int L, int R, int w) {
	if(mx[x] <= w) return -1; 
	if(L == R) return L;
	int mid = (L + R) >> 1;
	int ret = -1;
	if ((ret = query (x << 1 | 1, mid + 1, R, w)) != -1) return ret;
	if ((ret = query (x << 1, L, mid, w - sum[x << 1 | 1])) != -1) return ret;
	return assert (0), ret;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> m;
	L(i, 1, n) cin >> a[i], add (1, 0, Mx, a[i], 1);
	L(i, 1, m) cin >> b[i], add (1, 0, Mx, b[i], -1);
	cin >> q;
	while (q--) {
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1) {
			add (1, 0, Mx, a[x], -1);
			a[x] = y;
			add (1, 0, Mx, a[x], 1);
		} 
		else {
			add (1, 0, Mx, b[x], 1);
			b[x] = y;
			add (1, 0, Mx, b[x], -1);
		}
		cout << query (1, 0, Mx, 0) << '\n';
	}
	return 0;
}