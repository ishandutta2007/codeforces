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
int minn[N], flag[N];
void ad(int id, int x) { 
	minn[id] += x, flag[id] += x; 
}
void pushdown(int id) {
	if(flag[id]) ad(id << 1, flag[id]), ad(id << 1 | 1, flag[id]), flag[id] = 0;
}
void upd(int id) {
	minn[id] = min(minn[id << 1], minn[id << 1 | 1]);
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
	if(L == R) return minn[id] = min(minn[id], val), void();
	int mid = (L + R) >> 1;
	pushdown(id);
	if(wz <= mid) change(id << 1, L, mid, wz, val);
	else change(id << 1 | 1, mid + 1, R, wz, val);
	upd(id);
}
int get(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return minn[id];
	int mid = (L + R) >> 1, res = 1e9;
	pushdown(id);
	if(l <= mid) res = min(res, get(id << 1, L, mid, l, r));
	if(r > mid) res = min(res, get(id << 1 | 1, mid + 1, R, l, r));
	return res;
}
void Main() {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	if(n == 1) return cout << "1\n", void();
	add(1, 0, n, 1, n, 1e9);
	add(1, 0, n, 0, 0, 1);
	L(i, 2, n) {
		int mn = get(1, 0, n, 0, a[i] - 1);
		if(a[i] < n) mn = min(mn, get(1, 0, n, a[i] + 1, n));
		mn = min(mn + 1, get(1, 0, n, a[i], a[i]));
		
		// case1 : a[i - 1] 
		if(a[i] != a[i - 1]) add(1, 0, n, 0, n, 1);
		
		// case2 : i
		change(1, 0, n, a[i - 1], mn);
	}
	cout << minn[1] << "\n";
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}