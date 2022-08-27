// George1123 /qiang, SegmentTree /no 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
int n, m, f[N];
int maxn[N], flag[N];
void ad(int id, int x) { maxn[id] += x, flag[id] += x; }
void pushdown(int id) {
	if(flag[id]) ad(id << 1, flag[id]), ad(id << 1 | 1, flag[id]), flag[id] = 0;
}
void upd(int id) {
	maxn[id] = max(maxn[id << 1], maxn[id << 1 | 1]);
}
void add(int id, int L, int R, int l, int r, int val) {
	if(l <= L && R <= r) return ad(id, val), void();
	int mid = (L + R) / 2;
	pushdown(id);
	if(l <= mid) add(id << 1, L, mid, l, r, val);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, val);
	upd(id);
}
int upper(int x) {
	int L = 1, R = m, ans = m + 1;
	while(L <= R) {
		int mid = (L + R) / 2;
		if(f[mid] >= x) R = mid - 1, ans = mid;
		else L = mid + 1;
	}
	return ans;
}
int h, a[N];
int main() {
	scanf("%d%d%d", &n, &m, &h);
	L(i, 1, m) scanf("%d", &f[i]);
	sort(f + 1, f + m + 1);
	L(i, 1, m) add(1, 1, m, i, i, i);
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 1, m - 1) {
		int k = upper(h - a[i]);
		if(k <= m) add(1, 1, m, k, m, -1);
	}
	int cnt = 0;
	L(i, 1, n - m + 1) {
		int k = upper(h - a[i + m - 1]);
		if(k <= m) add(1, 1, m, k, m, -1);
		if(maxn[1] == 0) ++cnt;
		k = upper(h - a[i]);
		if(k <= m) add(1, 1, m, k, m, 1);
	}
	printf("%d\n", cnt);
	return 0;
}