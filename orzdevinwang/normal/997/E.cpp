#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define y second
#define x first
using namespace std;
const int N = 1.2e5 + 7;
int n, m, a[N];
int flag[N << 2], times[N << 2];
ll sum[N << 2], Ans[N];
struct PII { int minn, cnt; } f[N << 2];
PII operator + (PII aa, PII bb) {
	PII res; res.minn = min(aa.minn, bb.minn), res.cnt = 0;
	if(aa.minn == res.minn) res.cnt += aa.cnt;
	if(bb.minn == res.minn) res.cnt += bb.cnt;
	return res;
}
void ad(int id, int x) { 
	flag[id] += x, f[id].minn += x; 
}
void adt(int id, int x) {
	times[id] += x, sum[id] += 1ll * x * f[id].cnt;
}
void upd(int id) {
	sum[id] = sum[id << 1] + sum[id << 1 | 1];
	f[id] = f[id << 1] + f[id << 1 | 1];
}
void pushdown(int id) {
	if(flag[id]) ad(id << 1, flag[id]), ad(id << 1 | 1, flag[id]), flag[id] = 0;
	if(times[id]) {
		if(f[id].minn == f[id << 1].minn) adt(id << 1, times[id]);
		if(f[id].minn == f[id << 1 | 1].minn) adt(id << 1 | 1, times[id]);
		times[id] = 0;
	}
}
void build(int id, int L, int R) {
	if(L == R) return f[id].cnt = 1, f[id].minn = 0, void();
	int mid = (L + R) / 2;
	build(id << 1, L, mid), build(id << 1 | 1, mid + 1, R);
}
void add(int id, int L, int R, int l, int r, int val) {
	if(l <= L && R <= r) return ad(id, val), void();
	int mid = (L + R) / 2;
	pushdown(id);
	if(l <= mid) add(id << 1, L, mid, l, r, val);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, val);
	upd(id);
}
void fadd(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return adt(id, 1), void();
	int mid = (L + R) / 2;
	pushdown(id);
	if(l <= mid && f[id].minn == f[id << 1].minn) fadd(id << 1, L, mid, l, r);
	if(r > mid && f[id].minn == f[id << 1 | 1].minn) fadd(id << 1 | 1, mid + 1, R, l, r);
	upd(id);
}
ll query(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return sum[id];
	int mid = (L + R) / 2; ll res = 0;
	pushdown(id);
	if(l <= mid) res += query(id << 1, L, mid, l, r);
	if(r > mid) res += query(id << 1 | 1, mid + 1, R, l, r);
	return res;
}
int Gmax[N], tota, Gmin[N], totb;
int l[N], r[N];
vector<int> ve[N];
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]);
	build(1, 1, n);
	scanf("%d", &m);
	L(i, 1, m) scanf("%d%d", &l[i], &r[i]), ve[r[i]].push_back(i);
	L(i, 1, n) {
		if(i != 1) add(1, 1, n, 1, i - 1, -1);
		while(tota && a[i] > a[Gmax[tota]]) add(1, 1, n, Gmax[tota - 1] + 1, Gmax[tota], a[i] - a[Gmax[tota]]), --tota;
		while(totb && a[i] < a[Gmin[totb]]) add(1, 1, n, Gmin[totb - 1] + 1, Gmin[totb], a[Gmin[totb]] - a[i]), --totb;
		Gmax[++tota] = i, Gmin[++totb] = i;
		fadd(1, 1, n, 1, i);
		for(int v : ve[i]) Ans[v] = query(1, 1, n, l[v], r[v]);
	}
	L(i, 1, m) printf("%lld\n", Ans[i]);
    return 0;
}