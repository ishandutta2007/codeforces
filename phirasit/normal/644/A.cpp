#include <cstdio>

int n, a, b;

int main() {

	scanf("%d%d%d", &n, &a, &b);

	if(a*b < n) {
		printf("-1\n");
	}else {
		int cnt = 1;
		for(int i = 0;i < a;i++) {
			for(int j = 0;j < b;j++) {
				if(i % 2 and (b % 2 == 0) and cnt - 1 <= n) {
					printf("%d ", j % 2 ? (cnt - 1) : ((cnt + 1) > n ? 0 : (cnt+1)));
					cnt++;
				}else if(cnt > n) {
					printf("0 ");
				}else {
					printf("%d ", cnt++);
				}
			}
			printf("\n");
		}
	}
}