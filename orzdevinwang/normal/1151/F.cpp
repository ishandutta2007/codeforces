#include <bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
#define N 110
using namespace std;
const int mod = 1e9 + 7;
int n, k, m, now, s[N];
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) {
	return qpow(x, mod - 2);
}
struct Matix {
	int a[N][N];
} q, ans;
Matix operator * (Matix aa, Matix bb) {
	Matix res = {};
	L(i, 0, m) L(j, 0, m) res.a[i][j] = 0;
	L(i, 0, m) L(j, 0, m) L(k, 0, m) (res.a[i][j] += 1ll * aa.a[i][k] * bb.a[k][j] % mod) %= mod;
	return res;
}
Matix operator ^ (Matix aa, int bb) {
	Matix res = {};
	L(i, 0, m) L(j, 0, m) res.a[i][j] = (i == j);
	for(; bb; aa = aa * aa, bb >>= 1) if(bb & 1) res = res * aa;
	return res;
}
int main() {
	scanf("%d%d", &n, &k);
	L(i, 1, n) scanf("%d", &s[i]);
	L(i, 1, n) m += (s[i] == 0);
	L(i, 1, m) now += (s[i] == 0);
	int nny = ny(n * (n - 1) / 2);
	L(i, 0, m) {
		q.a[i][i] = 1ll * (m * (m - 1) / 2 + (n - m) * (n - m - 1) / 2 + (m - i) * (n + i - m * 2) + i * (m - i)) * nny % mod;
		if(i != 0) q.a[i][i - 1] = 1ll * i * (n + i - m * 2) * nny % mod;
		if(i != m) q.a[i][i + 1] = 1ll * (m - i) * (m - i) * nny % mod;
	}
	Matix pp = q ^ k;
	printf("%d\n", pp.a[now][m]);
	return 0;
}