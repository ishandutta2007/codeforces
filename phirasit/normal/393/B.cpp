#include <stdio.h>

double w[200][200];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			scanf("%lf", &w[i][j]);
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			printf("%.6lf ", (w[i][j] + w[j][i])/2);
		}
		printf("\n");
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			printf("%.6lf ", (w[i][j] - w[j][i])/2);
		}
		printf("\n");
	}
	return 0;
}