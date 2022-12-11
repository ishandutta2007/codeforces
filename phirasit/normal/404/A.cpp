#include <stdio.h>

#define N 310

char str[N][N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%s", str[i]);
	}
	char a = str[0][0], b = str[0][1];
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(i == j || j+i == n-1) {
				if(str[i][j] != a) {
					printf("NO\n");
					return 0;
				}
			}else {
				if(str[i][j] != b) {
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	if(a == b) {
		printf("NO\n");
	}else {
		printf("YES\n");
	}
	return 0;
}