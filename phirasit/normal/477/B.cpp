#include <stdio.h>

int arr[] = {1, 2, 3, 5};

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n", (6 * n - 1) * k);
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < 4;j++) {
			printf("%d ", (6 * i + arr[j]) * k);
		}
		printf("\n");
	}
	return 0;
}