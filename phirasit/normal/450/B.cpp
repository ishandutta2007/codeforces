#include <stdio.h>

#define MOD 1000000007

long long f1, f2, f3;
int n;

int main() {
	scanf("%I64d%I64d%d", &f1, &f2, &n);
	f1 = (f1 + MOD) % MOD;
	f2 = (f2 + MOD) % MOD;
	f3 = (f2 - f1 + MOD) % MOD;
	if(n%3 == 0) {
		if((n/3)%2 == 0) f3 = (MOD - f3) % MOD;
		printf("%I64d\n", f3);
	}else if(n%3 == 2) {
		if((n/3)%2 == 1) f2 = (MOD - f2) % MOD;
		printf("%I64d\n", f2);
	}else {
		if((n/3)%2 == 1) f1 = (MOD - f1) % MOD;
		printf("%I64d\n", f1);
	}
	return 0;
}