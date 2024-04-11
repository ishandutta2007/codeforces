#include <stdio.h>

#define N 1010

int n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	printf("%d\n", m * (m-1) / 2);
	if(k == 0) {
		for(int i = m;i > 0;i--) {
			for(int j = 1;j < i;j++) {
				printf("%d %d\n", j, j+1);
			}
		}
	}else {
		for(int i = 1;i <= m;i++) {
			for(int j = m;j > i;j--) {
				printf("%d %d\n", j, j-1);
			}
		}
	}
	return 0;
}