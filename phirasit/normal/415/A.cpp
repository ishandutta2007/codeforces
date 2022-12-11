#include <stdio.h>

int arr[110];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++) {
		int val;
		scanf("%d", &val);
		for(int j = val;j <= n;j++) {
			if(arr[j]) {
				break;
			}
			arr[j] = val;
		}
	}
	for(int i = 1;i <= n;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}