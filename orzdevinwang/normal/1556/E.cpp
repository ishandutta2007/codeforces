#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7;
int n, q, a[N], b[N];
ll pre[N], mx[N << 2], mn[N << 2];
void build (int id, int L, int R) {
	if(L == R) {
		mx[id] = mn[id] = pre[L];
		return ;
	}
	int mid = (L + R) >> 1;
	build (id << 1, L, mid);
	build (id << 1 | 1, mid + 1, R);
	mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
	mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
}
ll query1 (int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return mx[id];
	int mid = (L + R) >> 1; 
	ll res = -1e18;
	if(l <= mid) res = max(res, query1(id << 1, L, mid, l, r));
	if(r > mid) res = max(res, query1(id << 1 | 1, mid + 1, R, l, r));
	return res;
}
ll query2 (int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return mn[id];
	int mid = (L + R) >> 1; 
	ll res = 1e18;
	if(l <= mid) res = min(res, query2 (id << 1, L, mid, l, r));
	if(r > mid) res = min(res, query2 (id << 1 | 1, mid + 1, R, l, r));
	return res;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) cin >> b[i], a[i] = b[i] - a[i];
	L(i, 1, n) pre[i] = pre[i - 1] + a[i];
	build (1, 1, n);
	while (q--) {
		int l, r;
		cin >> l >> r;
		ll mx = query1(1, 1, n, l, r) - pre[l - 1], mn = query2(1, 1, n, l, r) - pre[l - 1];
		if(mn < 0 || pre[r] != pre[l - 1]) 
			cout << -1 << "\n";
		else 
			cout << mx << "\n";
	}
	return 0;
}