#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
ll sum[N << 2], lazy[N << 2];
void ADD(int id, int L, int R, ll val) { lazy[id] += val, sum[id] += (R - L + 1) * val; } 
void pushdown(int id, int L, int R) {
	int mid = (L + R) / 2;
	ADD(id << 1, L, mid, lazy[id]), ADD(id << 1 | 1, mid + 1, R, lazy[id]), lazy[id] = 0;
}
void add(int id, int L, int R, int l, int r, ll val) {
	if(l <= L && R <= r) return ADD(id, L, R, val), void();
	pushdown(id, L, R);
	int mid = (L + R) / 2;
	if(l <= mid) add(id << 1, L, mid, l, r, val);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, val);
	sum[id] = sum[id << 1] + sum[id << 1 | 1];
}
ll query(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return sum[id];
	pushdown(id, L, R);
	int mid = (L + R) / 2; ll res = 0;
	if(l <= mid) res += query(id << 1, L, mid, l, r);
	if(r > mid) res += query(id << 1 | 1, mid + 1, R, l, r);
	return res;
}
int n, m, f[N], l[N], r[N], fl[N], fr[N], stk[N], tot;
ll ans[N];
vector<int> vel[N], ver[N];
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) scanf("%d", &f[i]);
	L(i, 1, m) scanf("%d", &l[i]), vel[l[i]].push_back(i);
	L(i, 1, m) scanf("%d", &r[i]), ver[r[i]].push_back(i);
	L(i, 1, n) fr[i] = n + 1, fl[i] = 0;
	tot = 0;
	R(i, n, 1) {
		while(tot && f[i] > f[stk[tot]]) fl[stk[tot]] = i, --tot;
		stk[++tot] = i;
	}
	tot = 0;
	L(i, 1, n) {
		while(tot && f[i] > f[stk[tot]]) fr[stk[tot]] = i, --tot;
		stk[++tot] = i;
	}
	L(i, 1, n) {
		if(fl[i] + 1 <= i - 1) add(1, 1, n, fl[i] + 1, i - 1, 1);
		for(int x : ver[i]) ans[x] = query(1, 1, n, l[x], i);
	}
	memset(lazy, 0, sizeof(lazy));
	memset(sum, 0, sizeof(sum));
	R(i, n, 1) {
		add(1, 1, n, i, fr[i] - 1, 1);
		for(int x : vel[i]) ans[x] += query(1, 1, n, i, r[x]);
	}
	L(i, 1, m) printf("%lld ", ans[i]);
	puts("");
	return 0;
}