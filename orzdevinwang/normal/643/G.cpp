#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1.5e5 + 7;
int n, m, p, a[N];
struct node {
	int f[7] = {}, cnt[7] = {};
};
node operator + (node aa, node bb) {
	L(i, 1, p) {
		bool flag = 1;
		L(j, 1, p) if(bb.f[i] == aa.f[j] || aa.f[j] == 0) {
			flag = 0, aa.f[j] = bb.f[i], aa.cnt[j] += bb.cnt[i];
			break;
		}
		if(!flag) continue;
		int minn = 1, tmp = bb.cnt[i];
		L(j, 2, p) if(aa.cnt[j] < aa.cnt[minn]) minn = j;
		if(aa.cnt[minn] < bb.cnt[i]) tmp = aa.cnt[minn], aa.f[minn] = bb.f[i], aa.cnt[minn] = bb.cnt[i];
		L(j, 1, p) aa.cnt[j] -= tmp; 
	}
	return aa;
}
node seg[N << 2];
int flag[N << 2];
void xg(int x, int L, int R, int v) {
	fill(seg[x].f + 2, seg[x].f + 6, 0);
	fill(seg[x].cnt + 2, seg[x].cnt + 6, 0);
	seg[x].f[1] = flag[x] = v, seg[x].cnt[1] = R - L + 1;
}
void build(int id, int L, int R) {
	if(L == R) return xg(id, L, R, a[L]), void();
	int mid = (L + R) / 2;
	build(id << 1, L, mid), build(id << 1 | 1, mid + 1, R);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
void pushdown(int x, int L, int R) {
	int mid = (L + R) / 2;
	if(flag[x]) xg(x << 1, L, mid, flag[x]), xg(x << 1 | 1, mid + 1, R, flag[x]), flag[x] = 0;
}
void change(int id, int L, int R, int l, int r, int val) {
	if(l <= L && R <= r) return xg(id, L, R, val), void();
	int mid = (L + R) / 2;
	pushdown(id, L, R);
	if(l <= mid) change(id << 1, L, mid, l, r, val);
	if(r > mid) change(id << 1 | 1, mid + 1, R, l, r, val);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
node query(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return seg[id];
	int mid = (L + R) / 2;
	pushdown(id, L, R);
	if(r <= mid) return query(id << 1, L, mid, l, r);
	if(l > mid) return query(id << 1 | 1, mid + 1, R, l, r);
	return query(id << 1, L, mid, l, r) + query(id << 1 | 1, mid + 1, R, l, r);
}
int main() {
	scanf("%d%d%d", &n, &m, &p);
	p = 100 / p;
	L(i, 1, n) scanf("%d", &a[i]);
	build(1, 1, n);
	while(m--) {
		int opt, l, r, v;
		scanf("%d%d%d", &opt, &l, &r);
		if(opt == 1) scanf("%d", &v), change(1, 1, n, l, r, v);
		else {
			node res = query(1, 1, n, l, r);
			printf("%d ", p);
			L(i, 1, p) printf("%d ", res.f[i]);
			puts("");
		}
	}
	return 0;
}