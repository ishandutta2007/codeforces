#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>
#include <tuple>

#define mp make_pair
#define mtp make_tuple
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(m), &(n))
#define mul(x,y) (long long)(x)*(y)%mod

using namespace std;
typedef pair<int, int> pii;

const int R = 3162277;
const int mod = 1000000007;
const int inv = 500000004;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long n, m;
	scanf("%I64d %I64d", &n, &m);
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		long long q = n / i;
		if (q <= R) break;
		sum = sum + mul(i%mod, q%mod);
		sum = sum%mod;
	}
	for (int i = R; i >= 1; i--) {
		long long left = n / (i + 1) + 1;
		long long right = n / i;
		left = max(left, 1LL);
		right = min(right, m);
		if (left > right)continue;
		int coeff = mul(mul((left + right) % mod, (right - left + 1) % mod), inv);
		sum = sum + mul(coeff, i);
		sum = sum%mod;
	}
	int tot = mul(m%mod, n%mod);
	tot -= sum;
	tot = (tot + mod) % mod;
	printf("%d", tot);


	return 0;
}