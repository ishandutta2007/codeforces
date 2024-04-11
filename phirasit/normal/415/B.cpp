#include <stdio.h>

#define N 100010

int x[N];

long long a, b;
int n;

int main() {
	scanf("%d%I64d%I64d", &n, &a, &b);
	for(int i = 0;i < n;i++) {
		long long val;
		scanf("%I64d", &val);
		long long m = val * a / b;
		long long k = val * a - m * b;
		printf("%I64d ", k / a);
	}
	return 0;
}