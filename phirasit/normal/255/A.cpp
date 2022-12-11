#include <stdio.h>

int arr[3];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		int a;
		scanf("%d", &a);
		arr[i%3] += a;
	}
	if(arr[0] >= arr[1] && arr[0] >= arr[2]) {
		printf("chest\n");
	}else if(arr[1] >= arr[0] && arr[1] >= arr[2]) {
		printf("biceps\n");
	}else {
		printf("back\n");
	}
	return 0;
}