#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define mid ((l + r) / 2)
#define lch l, mid, o * 2
#define rch mid + 1, r, o * 2 + 1

using namespace std;
const int N = 3e5 + 5;
typedef long long ll;
int n, h[N], b[N], L[N];
ll f[N], c[N * 4], tag[N * 4];
void pu(int o) {
	c[o] = max(c[o * 2], c[o * 2 + 1]) + tag[o];
}
void upd(int L, int R, ll v, int l, int r, int o) {
	if(L <= l && r <= R) return c[o] += v, tag[o] += v, void();
	if(L <= mid) upd(L, R, v, lch);
	if(R > mid) upd(L, R, v, rch);
	pu(o);
}
ll qry(int L, int R, ll su, int l, int r, int o) {
	if(L <= l && r <= R) return c[o] + su;
	su += tag[o];
	ll res = -1e18;
	if(L <= mid) res = max(res, qry(L, R, su, lch));
	if(R > mid) res = max(res, qry(L, R, su, rch));
	return res;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &h[i]);
	rep(i, 1, n) scanf("%d", &b[i]);
	rep(i, 1, n) {
		upd(i - 1, i - 1, b[i], 0, n, 1);
		for(int& j = L[i] = i - 1; j && h[j] > h[i]; j = L[j])
			upd(L[j], j - 1, b[i] - b[j], 0, n, 1);
		f[i] = qry(0, i - 1, 0, 0, n, 1);
		upd(i, i, f[i], 0, n, 1);
	}
	cout << f[n];
	return 0;
}