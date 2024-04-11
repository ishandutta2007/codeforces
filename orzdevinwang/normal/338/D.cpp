// George1123 /qiang, SegmentTree /no 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e4 + 7;
ll n, m, f[N]; int k;
ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
void exgcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) return (void)(x = 1, y = 0);
	exgcd(b, a % b, y, x), y = y - (a / b) * x;
}
ll gsc(ll aa, ll bb, ll mod) {
	if(aa < 0) aa += mod; if(bb < 0) bb += mod;
	ll res = 0; for(; bb; (aa <<= 1) %= mod, bb >>= 1) if(bb & 1) (res += aa) %= mod;
	return res;
}
ll aa, bb;
int main() {
	scanf("%lld%lld", &n, &m);
	scanf("%d", &k);
	ll A = 1;
	L(i, 1, k) {
		scanf("%lld", &f[i]);
		ll GCD = gcd(A, f[i]);
		if(A / GCD > n / f[i]) return puts("NO"), 0;
		A = A / GCD * f[i];
	}
	if(A > n) return puts("NO"), 0;
	aa = f[1];
	L(i, 2, k) {
		ll a = f[i], b = (1 - i % f[i] + f[i]) % f[i];
		ll d = gcd(a, aa), c = b - bb, xm, fa, fb;
		exgcd(aa, a, fa, fb), fa = gsc(c / d, fa, a / d), xm = lcm(a, aa);
		bb = (gsc(fa, aa, xm) + bb + xm) % xm, aa = xm;
	}
	if(bb == 0) bb += aa;
	if(bb > m - k + 1) return puts("NO"), 0;
	L(i, 1, k) if(gcd(A, bb + i - 1) != f[i]) return puts("NO"), 0;
	puts("YES");
	return 0;
}