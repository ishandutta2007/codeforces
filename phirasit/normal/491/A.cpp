#include <stdio.h>

#define N 100010

int ans[N];
int a, b;

int main() {
	scanf("%d%d", &a, &b);
	int cnt = 1, n = a+b+1;
	for(int i = 0;i < b;i++) {
		ans[n-i] = cnt++;
	}
	for(int i = 0;i < a+1;i++) {
		ans[i+1] = cnt++;
	}
	for(int i = 1;i <= n;i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}