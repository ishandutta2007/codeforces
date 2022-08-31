// George1123 /qiang, SegmentTree /no 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
int n, m;
void fwtor(int *f, int flag) {
	for(int i = 2; i <= n; i <<= 1) 
		for(int l = (i >> 1), j = 0; j < n; j += i) 
			for(int k = j; k < j + l; k ++) 
				(f[k + l] += 1ll * flag * f[k] % mod) %= mod;
}
void fwtand(int *f, int flag) {
	for(int i = 2; i <= n; i <<= 1) 
		for(int l = (i >> 1), j = 0; j < n; j += i)
			for(int k = j; k < j + l; k ++) 
				(f[k] += 1ll * flag * f[k + l] % mod) %= mod;
}
void fwtxor(int *f, int flag) {
	for(int i = 2; i <= n; i <<= 1) 
		for(int l = (i >> 1), j = 0; j < n; j += i) 
			for(int k = j; k < j + l; k ++) {
				int pa = f[k], pb = f[k + l];
				f[k] = 1ll * flag * (pa + pb) % mod, f[k + l] = 1ll * flag * (pa - pb + mod) % mod;
			}
}
int A[N], B[N], C[N], fib[N];
int main() {
	n = (1 << 17);
	fib[0] = 0, fib[1] = 1;
	L(i, 2, n) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	scanf("%d", &m);
	while(m--) {
		int x; scanf("%d", &x);
		A[x] ++, B[x] ++;
	}
	L(i, 1, n - 1) for(int j = i; 1; j = (i & (j - 1))) {
		(C[i] += 1ll * B[j ^ i] * B[j] % mod) %= mod;
		if(!j) break;
	}
	fwtxor(A, 1);
	L(i, 0, n - 1) A[i] = 1ll * A[i] * A[i] % mod;
	fwtxor(A, (mod + 1) / 2);

	L(i, 0, n - 1) A[i] = 1ll * A[i] * fib[i] % mod, B[i] = 1ll * B[i] * fib[i] % mod, C[i] = 1ll * C[i] * fib[i] % mod;
	fwtand(A, 1), fwtand(B, 1), fwtand(C, 1);
	L(i, 0, n - 1) A[i] = 1ll * A[i] * B[i] % mod * C[i] % mod;
	fwtand(A, mod - 1);
	int sum = 0;
	L(i, 0, 16) (sum += A[1 << i]) %= mod;
	printf("%d\n", sum);
	return 0;
}