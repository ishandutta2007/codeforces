#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int n, m, a[N];
ll sum[N << 2];
int lazy[N << 2], mn[N << 2];
void ADD(int id, int L, int R, int val) { 
	lazy[id] = val, mn[id] = val, sum[id] = (ll) (R - L + 1) * val; 
} 
void pushdown(int id, int L, int R) {
	int mid = (L + R) >> 1;
	if(lazy[id]) ADD(id << 1, L, mid, lazy[id]), ADD(id << 1 | 1, mid + 1, R, lazy[id]), lazy[id] = 0;
}
void upd(int id) {
	sum[id] = sum[id << 1] + sum[id << 1 | 1];
	mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
}
void add(int id, int L, int R, int l, int r, int val) {
	if(l <= L && R <= r) {
		if(L == R) return mn[id] = sum[id] = max(mn[id], val), void();
		pushdown(id, L, R);
		int mid = (L + R) >> 1;
		if(mn[id << 1] > val) add(id << 1 | 1, mid + 1, R, l, r, val);
		else ADD(id << 1 | 1, mid + 1, R, val), add(id << 1, L, mid, l, r, val);
		upd(id);
		return;
	}
	pushdown(id, L, R);
	int mid = (L + R) >> 1;
	if(l <= mid) add(id << 1, L, mid, l, r, val);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, val);
	upd(id);
}
int query1(int id, int L, int R, int val) { //  <= val 
	if(L == R) {
		if(mn[id] <= val) return L;
		else return L + 1;
	}
	pushdown(id, L, R);
	int mid = (L + R) >> 1;
	if(mn[id << 1] <= val) return query1(id << 1, L, mid, val);
	else return query1(id << 1 | 1, mid + 1, R, val);
}
int query2(int id, int L, int R, ll val) { //  > val 
	if(L == R) {
		if(sum[id] > val) return L;
		else return L + 1;
	}
	pushdown(id, L, R);
	int mid = (L + R) >> 1;
	if(val < sum[id << 1]) return query2(id << 1, L, mid, val);
	else return query2(id << 1 | 1, mid + 1, R, val - sum[id << 1]);
}
ll query3(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return sum[id];
	pushdown(id, L, R);
	int mid = (L + R) >> 1; ll res = 0;
	if(l <= mid) res += query3(id << 1, L, mid, l, r);
	if(r > mid) res += query3(id << 1 | 1, mid + 1, R, l, r);
	return res;
}
void build(int id, int L, int R) {
	if(L == R) return mn[id] = sum[id] = a[L], void();
	int mid = (L + R) >> 1;
	build(id << 1, L, mid), build(id << 1 | 1, mid + 1, R), upd(id);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> a[i];
	build(1, 1, n);
	while(m--) {
		int opt, x, y;
		cin >> opt >> x >> y;
		if(opt == 1) {
			add(1, 1, n, 1, x, y);
			continue;
		}
		int ans = 0;
		while(x <= n) {
			int nx = max(x, query1(1, 1, n, y));
			if(nx > n) break;
			int pos = query2(1, 1, n, y + (nx == 1 ? 0 : query3(1, 1, n, 1, nx - 1)));
			if(pos == x) assert(0);
			ans += pos - nx, y -= query3(1, 1, n, nx, pos - 1), x = pos;
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
10 3
1 1 1 1 1 1 1 1 1 1    
1 2 2
1 1 10
2 1 11

*/