#include <stdio.h>

int n;

int main() {
	scanf("%d", &n);
	
	if(n <= 3) {
		printf("NO\n");
		return 0;
	}else if(n == 5) {
		printf("YES\n");
		printf("3 * 5 = 15\n");
		printf("2 * 4 = 8\n");
		printf("15 + 8 = 23\n");
		printf("23 + 1 = 24\n");
		return 0;
	}
	printf("YES\n");
	if(n%2 == 0) {
		int cnt = 0;
		for(int i = 5;i <= n;i+=2) {
			printf("%d - %d = 1\n", i + 1, i);
			cnt++;
		}
		for(int i = 0;i < cnt-1;i++) {
			printf("1 * 1 = 1\n");
		}
		if(cnt > 0) {
			printf("1 * 1 = 1\n");
		}
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
	}else {
		int cnt = 0;
		for(int i = 5;i <= n-2;i+=2) {
			printf("%d - %d = 1\n", i + 1, i);
			cnt++;
		}
		printf("1 - 1 = 0\n");
		printf("%d * 0 = 0\n", n);
		cnt--;
		for(int i = 0;i < cnt;i++) {
			printf("1 * 0 = 0\n");
		}
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
		printf("24 + 0 = 24\n");	
	}
	return 0;
}