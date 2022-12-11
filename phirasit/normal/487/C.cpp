#include <stdio.h>

int n;

long long PW(long long a, long long b) {
	if(b == 0) {
		return 1;
	}
	long long ans = PW(a, b / 2);
	ans = (ans * ans) % n;
	if(b%2) {
		ans = (a * ans) % n;
	}
	return ans;
}
long long MOD_INV(int x) {
	return PW(x, n-2);
}
bool prime(int x) {
	for(int i = 2;i*i <= x;i++) {
		if(x%i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	scanf("%d", &n);
	if(n < 4) {
		printf("YES\n");
		for(int i = 1;i <= n;i++) {
			printf("%d\n", i);
		}
		printf("\n");
	}else if(n == 4) {
		printf("YES\n");
		printf("1\n3\n2\n4\n");
	}else {
		if(prime(n)) {
			printf("YES\n");
			for(int i = 1;i <= n;i++) {
				if(i == 1) {
					printf("1\n");
				}else {
					long long ans = ((long long) i * MOD_INV(i-1)) % n;
					if(ans == 0) {
						ans = n;
					}
					printf("%I64d\n", ans);
				}
			}
		}else {
			printf("NO\n");
		}
	}
	return 0;
}