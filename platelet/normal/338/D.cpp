#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
 
using namespace std;
const int MI = 1e6;
typedef long long ll; 
ll read() {
	static streambuf* in = cin.rdbuf();
	#define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, MI), p1 == p2) ? -1 : *p1++)
	static char buf[MI], *p1, *p2;
	int c = gc; ll r = 0;
	while(c < 48) c = gc;
	while(c > 47) r = (r << 3) + (r << 1) + (c & 15), c = gc;
	return r;
}
ll n, m, a[10005]; int k;
ll mul(ll a, ll b, ll p, ll r = 0) {
	return (a * b - (ll)((long double)a / p * b + 0.5) * p + p) % p;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if(!b) return d = a, x = 1, y = 0, void();
	exgcd(b, a % b, d, y, x), y -= a / b * x;
}
int exCRT(ll& b1, ll& m1, ll b2, ll m2) {
	ll d, k1, k2; exgcd(m1, m2, d, k1, k2), m2 /= d;
	if((long double)m1 * m2 > n) return 0; return
	b1 = (b1 + mul(mul(k1 % m2, (b2 - b1) / d % m2, m2), m1, m1 * m2)) % (m1 *= m2), 1;
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0);
	n = read(), m = read(), k = read();
	ll b = 0, p = 1;
	rep(i, 1, k) {
		if(!exCRT(b, p, (1 - i) % a[i], a[i] = read()))
			return puts("NO"), 0;
	}
	if((b = (b + p - 1) % p + 1) > m - k + 1) return puts("NO"), 0;
	rep(i, 1, k) if(gcd(p, b + i - 1) ^ a[i]) return puts("NO"), 0;
	return puts("YES"), 0;
}