#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e4 + 7;
const int mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f; 
}
int n, k, invn, a[N];
int tmp[N * 20], *Id = tmp;
int sav[N], sv[N];
void Mul(int *f, int *g, int *ans, int n, int m) {
	L(i, 0, n + m - 2) sav[i] = 0;
	L(i, 0, n - 1) L(j, 0, m - 1) (sav[i + j] += (ll) f[i] * g[j] % mod) %= mod;
	L(i, 0, n + m - 2) ans[i] = sav[i];
} 
int *A[N], *B[N];
void div1(int id, int l, int r) {
	A[id] = Id, Id += r - l + 2, B[id] = Id, Id += r - l + 1;
	if(l == r) {
		A[id][0] = a[l];
		A[id][1] = mod - 1;
		B[id][0] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	div1(id << 1, l, mid), div1(id << 1 | 1, mid + 1, r);
	Mul(A[id << 1], A[id << 1 | 1], A[id], mid - l + 2, r - mid + 1);
	L(i, 0, r - l) sv[i] = 0;
	Mul(A[id << 1], B[id << 1 | 1], B[id], mid - l + 2, r - mid);
	Mul(B[id << 1], A[id << 1 | 1], sv, mid - l + 1, r - mid + 1);
	L(i, 0, r - l) (B[id][i] += sv[i]) %= mod;
}
int ans = 0;
int main() {
	n = read(), k = read(), invn = qpow(n);
	L(i, 1, n) a[i] = read();
	div1(1, 1, n);
	int now = 1;
	L(i, 0, n - 1) {
		now = (ll) now * (k - i) % mod * invn % mod;
		(ans += (ll) B[1][i] * now % mod * qpow(i + 1) % mod) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}