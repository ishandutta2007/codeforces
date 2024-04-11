#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N]; 
int maxn[N], flag[N];
void ad(int id, int x) { 
	maxn[id] += x, flag[id] += x; 
}
void pushdown(int id) {
	if(flag[id]) ad(id << 1, flag[id]), ad(id << 1 | 1, flag[id]), flag[id] = 0;
}
void upd(int id) {
	maxn[id] = max(maxn[id << 1], maxn[id << 1 | 1]);
}
void add(int id, int L, int R, int l, int r, int val) {
	if(l <= L && R <= r) return ad(id, val), void();
	int mid = (L + R) >> 1;
	pushdown(id);
	if(l <= mid) add(id << 1, L, mid, l, r, val);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, val);
	upd(id);
}
void change(int id, int L, int R, int wz, int val) {
	if(L == R) return maxn[id] = max(maxn[id], val), void();
	int mid = (L + R) >> 1;
	pushdown(id);
	if(wz <= mid) change(id << 1, L, mid, wz, val);
	else change(id << 1 | 1, mid + 1, R, wz, val);
	upd(id);
}
int get(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return maxn[id];
	int mid = (L + R) >> 1, res = 0;
	pushdown(id);
	if(l <= mid) res = max(res, get(id << 1, L, mid, l, r));
	if(r > mid) res = max(res, get(id << 1 | 1, mid + 1, R, l, r));
	return res;
}
void Main() {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	if(n == 1) return cout << "1\n", void();
	add(1, 0, n, 0, 0, 1);
	L(i, 2, n) {
		int mx = get(1, 0, n, 0, a[i] - 1);
		if(a[i] < n) mx = max(mx, get(1, 0, n, a[i] + 1, n));
		mx = max(mx + 1, get(1, 0, n, a[i], a[i]));
		
		// case1 : a[i - 1] 
		if(a[i] != a[i - 1]) add(1, 0, n, 0, n, 1);
		
		// case2 : i
		change(1, 0, n, a[i - 1], mx);
	}
	cout << maxn[1] << "\n";
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}