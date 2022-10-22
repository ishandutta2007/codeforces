#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 3e6 + 5;
const ll P = 1e9 + 7;

int n, q;
ll inv[N], g[N], f[N];

int main() {
	// for(cin >> T; T--;) solve();
	cin >> n >> q, n = (n + 1) * 3;
	inv[1] = 1;
	rep(i, 2, n) inv[i] = (P - P / i) * inv[P % i] % P;
	g[0] = 1;
	rep(i, 1, n) g[i] = g[i - 1] * (n + 1 - i) % P * inv[i] % P;
	per(i, n - 3, 1) f[i] = (g[i + 3] - 3 * f[i + 1] - 3 * f[i + 2]) % P;
	int x;
	while(q--) scanf("%d", &x), printf("%lld\n", (f[x] + P) % P);
}