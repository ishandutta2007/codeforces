#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <assert.h>
using namespace std;
const int N = 200000;
const int mod = 1000003;
const int inv2 = (mod + 1) / 2;
#define mul(x,y) (long long)(x)*(y)%mod

int mpow(int n, int e) {
	if (!e) return 1;
	int t = mpow(n, e / 2);
	t = mul(t, t);
	if (e & 1) t = mul(t, n);
	return t;
}
int main() {
	long long n, k; scanf("%I64d %I64d", &n, &k);
	if (n < 60 && (1LL << (int)n) < k) {
		puts("1 1"); return 0;
	}
	long long em = 0;
	for (int i = 1; i < 60 && i <= n; i++) {
		long long r = 1LL << i;
		em += (k + r - 1) / r;
	}
	em += (n - min(n, 59LL));
	int nn = n % (mod - 1);
	int kk = k % (mod - 1);
	em = em % (mod - 1);
	nn = (long long)nn*kk % (mod - 1) - (int)em;
	if (nn < 0) nn += (mod - 1);
	int B = mpow(2, nn);
	if (k >= mod) {
		printf("%d %d\n", B, B);
		return 0;
	}
	int C = mpow(inv2, (int)em);
	int D = mpow(2, n % (mod - 1));
	int A = 1;
	for (int i = 0; i < k; i++) {
		A = mul(A, D - i);
		if (A < 0) A += mod;
	}
	A = mul(A, C);
	A = B - A;
	if (A < 0) A += mod;
	printf("%d %d\n", A, B);
}