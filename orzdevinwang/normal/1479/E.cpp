#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define ull unsigned long long
#define sz(a) ((int) (a).size())
using namespace std;
const int M = 1145, mod = 998244353;
int n, s, a[M], ns, now = 1;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
#define ull unsigned long long
inline ull calc(const ull & x) {
	return x - (__uint128_t(x) * 9920937979283557439ull >> 93) * 998244353;
}
int a1, a2, b1, b2; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i], (s += a[i]) %= mod;
	sort(a + 1, a + n + 1);
	b1 = 0, b2 = 1, a1 = mod - 2, a2 = 1;
	while(now <= n && a[now] == 0) ++now;
	L(i, 1, s) {
		while(now <= n && a[now] == i) (ns += (ll) a1 * qpow(a2) % mod) %= mod, ++now;
		if(i < s) 
			b1 = calc(calc((ull) a1 * (3 * s - 2 * i)) * b2 + mod - calc(calc((ull) b1 * (2 * s - i)) * a2)), b2 = (ll) a2 * b2 % mod * (s - i) % mod, swap(a1, b1), swap(a2, b2);
	}
	cout << (ns + mod - (ll) a1 * qpow(a2) % mod) % mod << "\n";
	return 0;
}