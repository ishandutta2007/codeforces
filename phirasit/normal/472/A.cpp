#include <stdio.h>

int n;

int prime(int k) {
	if(k == 1) {
		return 0;
	}
	for(int i = 2;i*i <= k;i++) {
		if(k%i == 0) {
			return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	for(int i = 1;i < n;i++) {
		if(!prime(i) == 0 && !prime(n-i) == 0) {
			printf("%d %d\n", i, n-i);
			return 0;
		}
	}
	return 0;
}