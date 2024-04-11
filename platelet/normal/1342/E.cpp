#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 2e5 + 5, P = 998244353;

int n;
ll K, fac[N], ifac[N];
ll Pow(ll a, int n, ll r = 1) {
	for(; n; n >>= 1, a = a * a % P)
	if(n & 1) r = r * a % P;
	return r;
}
ll C(int n, int m) {
	return fac[n] * ifac[m] % P * ifac[n - m] % P;
}
int main() {
	cin >> n >> K;
	if(K >= n) puts("0"), exit(0);
	rep(i, 0, n) fac[i] = i ? fac[i - 1] * i % P : 1;
	if(!K) cout << fac[n], exit(0);
	per(i, n + 1, 1) ifac[i - 1] = i > n ? Pow(fac[n], P - 2) : ifac[i] * i % P;
	ll ans = 0;
	rep(i, K, n) (ans += (i - K & 1 ? -1 : 1) * C(i, K) % P * C(n, i) % P * Pow(n - i, n)) %= P;
	cout << (ans + P) * 2 % P;
}