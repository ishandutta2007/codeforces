#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 2005;
typedef long long ll;
const ll P = 998244353;

ll Pow(ll a, int n, ll r = 1) {
	for(; n; n /= 2, a = a * a % P)
	if(n & 1) r = r * a % P;
	return r;
}
int n; ll a, b, p[N], p1[N], h[N][N], g[N], f[N];

int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n >> a >> b, a = a * Pow(b, P - 2) % P;
	p[0] = p1[0] = 1;
	rep(i, 1, n) p[i] = p[i - 1] * a % P, p1[i] = p1[i - 1] * (1 - a) % P;
	rep(i, 0, n) h[i][0] = 1;
	rep(i, 1, n) rep(j, 1, i) h[i][j] = (h[i - 1][j - 1] * p1[i - j] + h[i - 1][j] * p[j]) % P;
	rep(i, 1, n) {
		g[i] = 1;
		rep(j, 1, i - 1) (g[i] -= g[j] * h[i][j]) %= P;
	}
	rep(i, 1, n) {
		f[i] = g[i] * (i * (i - 1) / 2) % P;
		rep(j, 1, i - 1) (f[i] += g[j] * h[i][j] % P * (i * (i - 1) / 2 + f[j] + f[i - j] - (i - j) * (i - j - 1) / 2)) %= P;
		(f[i] *= Pow(1 - g[i], P - 2)) %= P;
	}
	cout << (f[n] + P) % P;
	return 0;
}