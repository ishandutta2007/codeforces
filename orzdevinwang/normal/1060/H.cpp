#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 300;
int d, mod, f[N][N], h[N][N];
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
void Guess(int n) {
	L(i, 1, n) {
		int p = -1;
		L(j, i, n) if(f[j][i]) p = j;
		assert(p > 0);
		swap(f[i], f[p]), swap(h[i], h[p]);
		int iv = qpow(f[i][i]);
		L(j, 1, n) f[i][j] = (ll) f[i][j] * iv % mod, h[i][j] = (ll) h[i][j] * iv % mod;
		L(j, 1, n) if(j != i) {
			int t = mod - f[j][i];
			L(k, 1, n) 
				(f[j][k] += (ll) f[i][k] * t % mod) %= mod, 
				(h[j][k] += (ll) h[i][k] * t % mod) %= mod;
		}
	}
}
int tot = 3, pw[N], pos[N];
int getid(int x) {
	(x += mod - 1) %= mod;
	int cur = ++tot;
	L(i, 0, 30) if(x >> i & 1) cout << "+ " << cur << ' ' << pw[i] << ' ' << cur << '\n';
	return cur;
}
int mutiply(int x, int w) {
	int cur = getid(0), now = x;
	L(i, 0, 29) {
		if(w >> i & 1) 
			cout << "+ " << cur << ' ' << now << ' ' << cur << '\n';
		if((1 << i) <= w) 
			cout << "+ " << now << ' ' << now << ' ' << tot + 1 << '\n', now = ++tot;	
	}
	return cur;
}
int getpw(int x) {
	pos[0] = x;
	L(i, 1, d + 1) 
		pos[i] = ++tot, cout << "+ " << pos[i] << ' ' << pos[i - 1] << ' ' << pos[i] << '\n';
	L(i, 1, d + 1) 
		cout << "^ " << pos[i] << ' ' << pos[i] << '\n'; 
	int cur = 0;
	L(i, 1, d + 1) {
		int u = mutiply(pos[i], h[3][i]);
		if(!cur) cur = u;
		else cout << "+ " << cur << ' ' << u << ' ' << cur << '\n';
	}
	return cur;
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> d >> mod;
	init (d);
	pw[0] = tot;
	L(i, 1, 30) 
		pw[i] = ++tot, cout << "+ " << pw[i - 1] << ' ' << pw[i - 1] << ' ' << pw[i] << '\n';
	L(i, 1, d + 1) {
		L(j, 0, d) f[i][j + 1] = (ll) C(d, j) * qpow(i, d - j) % mod;
		h[i][i] = 1;
	}
	Guess(d + 1);
	int cur = ++tot, tc = ++tot;
	cout << "+ " << 1 << ' ' << 2 << ' ' << tc << '\n';
	int u = getpw(1), v = getpw(2), z = getpw(tc);
	u = mutiply(u, mod - 1);
	v = mutiply(v, mod - 1);
	cout << "+ " << u << ' ' << v << ' ' << v << '\n';
	cout << "+ " << v << ' ' << z << ' ' << cur << '\n';
	cur = mutiply(cur, (mod + 1) / 2);
	cout << "f " << cur << '\n';
	return 0;
}