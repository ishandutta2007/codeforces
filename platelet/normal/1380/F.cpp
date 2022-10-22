#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define mid ((l + r) >> 1)
#define lch l, mid, o << 1
#define rch mid + 1, r, o << 1 | 1

using namespace std;
const int N = 5e5 + 5, P = 998244353;
int n, m, c[N]; long long AB[N*4], A[N*4], B[N*4], O[N*4];
void pushup(int o, int x) {
	x = x < 10 || x > 18 ? 0 : 19 - x;
	AB[o] = (AB[o<<1] * AB[o<<1|1] + A[o<<1] * B[o<<1|1] % P * x) % P;
	A[o] = (AB[o<<1] * A[o<<1|1] + A[o<<1] * O[o<<1|1] % P * x) % P;
	B[o] = (B[o<<1] * AB[o<<1|1] + O[o<<1] * B[o<<1|1] % P * x) % P;
	O[o] = (B[o<<1] * A[o<<1|1] + O[o<<1] * O[o<<1|1] % P * x) % P;
}
void bld(int l, int r, int o) {
	if(l == r) return scanf("%1d", &c[l]), AB[o] = c[l] + 1, A[o] = B[o] = 1, void();
	bld(lch), bld(rch), pushup(o, c[mid] * 10 + c[mid+1]);
}
void upd(int p, int l, int r, int o) {
	if(l == r) return scanf("%d", &c[l]), AB[o] = c[l] + 1, void();
	if(p <= mid) upd(p, lch); else upd(p, rch);
	pushup(o, c[mid] * 10 + c[mid+1]);
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m, bld(1, n, 1);
	for(int p; m--; printf("%lld\n", AB[1])) scanf("%d", &p), upd(p, 1, n, 1);
	return 0;
}