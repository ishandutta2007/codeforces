#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define upd(a, b) (a = min(a, b))

using namespace std;
typedef long long ll;
const ll P = 998244353;
int K, A[20];
ll ten[20], l, r, g[20][1 << 10][2][2], f[20][1 << 10][2][2];
ll calc(ll x) {
	mem(g, 0), mem(f, 0);
	int tp = 0;
	while(x) A[++tp] = x % 10, x /= 10;
	For(S, 0, 1 << 10) if(__builtin_popcount(S) <= K)
	rep(le, 0, 1) rep(hv, 0, 1) g[0][S][le][hv] = 1;
	rep(i, 1, tp) For(S, 0, 1 << 10) if(__builtin_popcount(S) <= K)
	rep(le, 0, 1) rep(j, 0, le ? 9 : A[i]) rep(hv, 0, 1) {
		int k = i - 1, Le = le || j < A[i], Hv = hv && !j, T = Hv ? 0 : S | 1 << j;
		(g[i][S][le][hv] += g[k][T][Le][Hv]) %= P;
		(f[i][S][le][hv] += f[k][T][Le][Hv] + j * ten[i - 1] % P * g[k][T][Le][Hv]) %= P;
	}
	return f[tp][0][0][1];
}
int main() {
	ten[0] = 1;
	rep(i, 1, 17) ten[i] = ten[i - 1] * 10 % P;
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> l >> r >> K;
	cout << (calc(r) - calc(l - 1) + P) % P;
	return 0;
}