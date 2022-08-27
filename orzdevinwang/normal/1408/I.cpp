#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int M = 18, N = (1 << (M - 1)), mod = 998244353;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, k, c, fac[N], ifac[N], inv[N], all;
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}

struct node { int f[M]; } s[N];
int cnt[N], tot, fs = 1;
bool operator < (node a, node b) { L(i, 0, k) if(a.f[i] ^ b.f[i]) return a.f[i] < b.f[i]; return false; }
map < node, int > mp;
int a[N], ns[N], ln[N][M], v[N], g[N];

void Exp(int *f, int len) { 
	g[0] = 1;
	L(i, 1, len - 1) L(j, 1, i) (g[i] += (ll) g[i - j] * f[j] % mod * j % mod * inv[i] % mod) %= mod;
	L(i, 0, len - 1) f[i] = g[i], g[i] = 0;
}
void Ln(int *f, int len) { 
	g[0] = 0;
	L(i, 1, len - 1) {
		g[i] = f[i];
		L(j, 1, i - 1) (g[i] += mod - (ll) g[j] * f[i - j] % mod * j % mod * inv[i] % mod) %= mod;
	}
	L(i, 0, len - 1) f[i] = g[i], g[i] = 0;
}
void IFWT(int *f, int len) {
	for(int i = 2; i <= len; i <<= 1) 
		for(int j = 0, l = (i >> 1); j < len; j += i) 
			for(int k = j; k < j + l; k++) {
				int pa = f[k], pb = f[k + l];
				f[k] = (pa + pb) % mod, f[k + l] = (pa + mod - pb) % mod;
			}
	L(i, 0, len - 1) f[i] = (ll) f[i] * inv[len] % mod;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k >> c, init(max(max(n, k), 1 << c) + 5);
	L(i, 1, n) {
		cin >> a[i], all ^= a[i];
		node w;
		L(j, 0, k) w.f[j] = (a[i] ^ (a[i] - j));
		mp[w] ++;
	}
	for(auto w : mp) ++tot, s[tot] = w.first, cnt[tot] = w.second;
	L(i, 0, (1 << (k + 1)) - 1) {
		L(j, 0, k) ln[i][j] = ((i >> j & 1) ? mod - ifac[j] : ifac[j]);
		Ln(ln[i], k + 1);
	}
	L(i, 0, (1 << c) - 1) {
		L(j, 0, k) v[j] = 0;
		L(j, 1, tot) {
			int msk = 0;
			L(t, 0, k) if(__builtin_parity(i & s[j].f[t])) msk |= (1 << t);
			L(t, 0, k) (v[t] += (ll) ln[msk][t] * cnt[j] % mod) %= mod;
		}
		Exp(v, k + 1), ns[i] = v[k];
	}
	IFWT(ns, 1 << c);
	L(i, 1, k) fs = (ll) fs * inv[n] % mod;
	L(i, 0, (1 << c) - 1) cout << (ll) ns[all ^ i] * fs % mod * fac[k] % mod << " ";
	cout << "\n";
	return 0;
}