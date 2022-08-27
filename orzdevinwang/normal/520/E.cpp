#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
void Min(int &x, int y) { if(x > y) x = y; }
void Max(int &x, int y) { if(x < y) x = y; }
const int N = 1e6 + 7; 
const int mod = 1e9 + 7;
int n, k, f[N], fac[N], ifac[N], hzs[N], qzs[N];
int tpow[N], itpow[N];
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res; 
}
void init(int x) {
	fac[0] = 1;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod;
	ifac[x] = qpow(fac[x]);
	R(i, x, 1) ifac[i - 1] = (ll) ifac[i] * i % mod;
	int it = qpow(10);
	tpow[0] = itpow[0] = 1;
	L(i, 1, x) tpow[i] = (ll) tpow[i - 1] * 10 % mod;
	L(i, 1, x) itpow[i] = (ll) itpow[i - 1] * it % mod;
}
int C(int x, int y) {
	if(x < y) return 0;
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int hz[N], ans;
char s[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	cin >> s + 1;
	init(n);
	L(i, 1, n) f[i] = s[i] - '0';
	R(i, n, 1) hz[i] = ((ll) f[i] * tpow[n - i] % mod + hz[i + 1]) % mod;
	if(k == 0) {
		cout << hz[1] << endl;
		return 0;
	}
	if(k > 1) {
		int res = 0;
		R(r, n - 1, 1) hzs[r] = (hzs[r + 1] + (ll) hz[r + 1] * itpow[n - r] % mod) % mod;
		L(l, 2, n - 1) qzs[l] = (qzs[l - 1] + (ll) hz[l] * itpow[n - l] % mod) % mod;
		L(len, 1, n - k) {
			int tmp = 0;
			(tmp += mod - hzs[len + 1]) %= mod;
			(tmp += (ll) qzs[n - len] * tpow[len - 1] % mod) %= mod;
			tmp = (ll) tmp * fac[n - len - 2] % mod * ifac[n - len - k] % mod;
			(res += tmp) %= mod;
		} 
		(ans += (ll) res * ifac[k - 2] % mod) %= mod;
	}
	L(i, 1, n - 1) (ans += (ll) (hz[1] - hz[i + 1] + mod) * itpow[n - i] % mod * C(n - i - 1, k - 1) % mod) %= mod;
	L(i, 2, n) (ans += (ll) hz[i] * C(i - 2, k - 1) % mod) %= mod;
	cout << ans << endl;
	return 0;
}