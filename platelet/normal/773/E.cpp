#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define mid ((l + r) / 2)
#define ls o * 2
#define rs o * 2 + 1
#define lch l, mid, ls
#define rch mid + 1, r, rs

using namespace std;
const int N = 5e5 + 5, M = N * 4;
int n, a[N], g[N], v[M], s[M], t[M], c[M];
void ins(int p, int x, int rk, int l, int r, int o) {
	s[o]++;
	if(l == r) return v[o] = x, c[o] = x + rk, void();
	rk -= t[o];
	if(p <= mid) ins(p, x, rk + s[rs], lch);
	else ins(p, x, rk, rch), t[ls]++, c[ls]++;
	c[o] = min(c[ls], c[rs]) + t[o];
	v[o] = s[ls] ? v[ls] : v[rs];
}
int qry(int rk, int l, int r, int o) {
	return l < r ? s[rs] && v[rs] + rk + s[ls] <= 0 ? qry(rk + s[ls], rch) : qry(rk, lch) : l;
}
int sz(int p, int l, int r, int o) {
	return l < r ? p <= mid ? sz(p, lch) : sz(p, rch) + s[ls] : s[o];
}
int qry(int p, int su, int l, int r, int o) {
	if(p <= l) return c[o] + su;
	su += t[o];
	int re = 1e9;
	if(p <= mid && s[ls]) re = min(re, qry(p, su, lch));
	if(s[rs]) re = min(re, qry(p, su, rch));
	return re;
}
int main() {
	mem(c, 63);
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &a[i]), g[i] = a[i];
	sort(g + 1, g + n + 1);
	rep(i, 1, n) {
		int p = lower_bound(g + 1, g + n + 1, a[i]) - g;
		ins(p, a[i], 0, 1, n, 1), g[p]--;
		int l = v[1] <= -1 ? qry(1, 1, n, 1) : 0, s = l ? sz(l, 1, n, 1) : 0;
		printf("%d\n", min(i - s * 2, qry(l + 1, 0, 1, n, 1)));
	}
	return 0;
}