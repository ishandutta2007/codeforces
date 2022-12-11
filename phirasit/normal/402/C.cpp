#include <stdio.h>

#define N 30

int arr[N][N];
int n, p;

void evaluate(void) {
	scanf("%d%d", &n, &p);
	int cnt = 0;
	for(int sk = 1;cnt < 2*n+p;sk++) {
		for(int i = 1;i <= n;i++) {
			if(i+sk <= n && cnt < 2*n+p) {
				cnt++;
				printf("%d %d\n", i, i+sk);
			}
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		evaluate();
	}
	return 0;
}