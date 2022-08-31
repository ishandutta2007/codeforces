#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e6 + 7;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
const int mod = 1e9 + 7;
int n, m, q, f[N], tot, ans;
int fac[N], ifac[N];
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
void minit(int x) {
	fac[0] = 1;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod;
	ifac[x] = qpow(fac[x]);
	R(i, x, 1) ifac[i - 1] = (ll) ifac[i] * i % mod;
}
int C(int x, int y) {
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
void Main() {
	ans = 1;
	n = read(), m = read();
	L(i, 2, sqrt(n)) if(n % i == 0) {
		int cnt = 0;
		while(n % i == 0) {
			n /= i, ++cnt;
		}
		ans = (ll) ans * C(m + cnt - 1, cnt) % mod;
	}
	if(n > 1) {
		ans = (ll) ans * m % mod;
	}
	ans = (ll) ans * qpow(2, m - 1) % mod;
	printf("%d\n", ans);
}
int main() {
	minit(2e6);
	q = read();
	while(q--) Main();
	return 0;
}