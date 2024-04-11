#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e5;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
const int inv4 = 748683265;
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) { return qpow(x, mod - 2); }
void fwt(int *f, int len, int flag) {
	for(int i = 2; i <= len; i <<= 1) 
		for(int j = 0, l = (i >> 1); j < len; j += i) 
			for(int k = j; k < j + l; k ++) {
				int pa = f[k], pb = f[k + l];
				if(flag == 1) f[k] = (pa + pb) % mod, f[k + l] = (pa - pb + mod) % mod;
				else f[k] = 1ll * inv2 * (pa + pb) % mod, f[k + l] = 1ll * inv2 * (pa - pb + mod) % mod;
			}
}
int n, m, x, y, z, p1, p2, p3, p4;
int a[N], b[N], c[N], sum;
int A[N], B[N], C[N], D[N], ans[N];
int main() {
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &z);
	m = (1 << m);
	p1 = (0ll + x + y + z + mod) % mod;
	p2 = ((0ll + x + y - z) % mod + mod) % mod;
	p3 = ((0ll + x - y + z) % mod + mod) % mod;
	p4 = ((0ll + x - y - z) % mod + mod) % mod;
	// cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
	L(i, 1, n) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]), sum ^= a[i];
		b[i] ^= a[i], c[i] ^= a[i];
		B[b[i]] ++, C[c[i]] ++, D[b[i] ^ c[i]] ++;
	}
	fwt(B, m, 1), fwt(C, m, 1), fwt(D, m, 1);
	L(i, 0, m - 1) {
		A[i] = n;
		// cout << "arrry : ";
		// cout << A[i] << " " << B[i] << " " << C[i] << " " << D[i] << endl;
		int a = (0ll + A[i] + B[i] + C[i] + D[i] + mod + mod) % mod * inv4 % mod;
		int b = (0ll + A[i] + B[i] - C[i] - D[i] + mod + mod) % mod * inv4 % mod;
		int c = (0ll + A[i] - B[i] + C[i] - D[i] + mod + mod) % mod * inv4 % mod;
		int d = (0ll + A[i] - B[i] - C[i] + D[i] + mod + mod) % mod * inv4 % mod;
//		 cout << a << " " << b << " " << c << " " << d << endl;
		ans[i] = 1ll * qpow(p1, a) * qpow(p2, b) % mod * qpow(p3, c) % mod * qpow(p4, d) % mod;
		// cout << ans[i] << " ";
	}
	// puts("");
	fwt(ans, m, -1);
	L(i, 0, m - 1) printf("%d ", ans[i ^ sum]);
	puts("");
	return 0;
}