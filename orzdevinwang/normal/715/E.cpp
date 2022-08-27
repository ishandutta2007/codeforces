#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 514, mod = 998244353;
#define add(a,b) (a + b >= mod ? a + b - mod : a + b)
#define dec(a,b) (a < b ? a - b + mod : a - b)
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N], S1[N][N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;

	S1[0][0] = 1;
	L(i, 1, x) L(j, 1, i) S1[i][j] = (S1[i - 1][j - 1] + (ll) S1[i - 1][j] * (i - 1) % mod) % mod; 
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, p[N], q[N], c1, c2, m, ns[N];

void Mul (int *a, int *b, int *c, int n, int m) {
	static int Ns[N];
	L(i, 0, n + m) Ns[i] = 0;
	L(i, 0, n) L(j, 0, m) (Ns[i + j] += (ll) a[i] * b[j] % mod) %= mod;
	L(i, 0, n + m) c[i] = Ns[i];
}

int A[N], B[N], H[N], nowc;

int f[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
bool cir[N], ok1[N], ok2[N];
void merge (int x, int y) {
	x = find(x), y = find(y);
	ok1[x] |= ok1[y], ok2[x] |= ok2[y], f[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n, init(n);
	L(i, 1, n) f[i] = i;
	L(i, 1, n) cin >> p[i];
	L(i, 1, n) cin >> q[i];
	L(i, 1, n) {
		if(p[i] && q[i]) {
			if(find(p[i]) != find(q[i])) merge(p[i], q[i]);
			else cir[find(p[i])] = true;
		}
		if(p[i] && !q[i]) ok1[find(p[i])] = true;
		if(!p[i] && q[i]) ok2[find(q[i])] = true;
		if(!p[i] && !q[i]) ++m;
	}
	L(i, 1, n) if(find(i) == i) {
		if(cir[i]) ++nowc;
		else if(ok1[i] && ok2[i]) ++m;
		else if(ok1[i]) ++c1;
		else if(ok2[i]) ++c2;
	}
	L(k, 0, c1) {
		int W = 1;
		L(a, 0, c1 - k) A[k] = add(A[k], (ll) C(c1, a) * S1[c1 - a][k] % mod * W % mod), W = (ll) W * (m + a) % mod;
	}
	L(k, 0, c2) {
		int W = 1;
		L(a, 0, c2 - k) B[k] = add(B[k], (ll) C(c2, a) * S1[c2 - a][k] % mod * W % mod), W = (ll) W * (m + a) % mod;
	}
	L(k, 0, m) H[k] = (ll) S1[m][k] * fac[m] % mod;
	Mul(A, B, ns, c1, c2), Mul(ns, H, ns, c1 + c2, m);
	R(i, n, 0) ns[i] = i >= nowc ? ns[i - nowc] : 0;
	R(i, n, 1) cout << ns[i] << ' ';
	return 0;
}