#include <stdio.h>

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0;i <= n;i += m) {
		if(i <= n && n <= 2*i) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;	
}