#include <stdio.h>

#define N 1000010

int arr[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	int cnt = 0, mn;
	for(int i = 0;i < n;i++) {
		if(arr[i] > arr[(i+1) % n]) {
			cnt++;
			mn = i;
		}
	}
	if(cnt == 0) {
		printf("%d\n", 0);
	}else if(cnt == 1) {
		printf("%d\n", n - mn - 1);
	}else {
		printf("%d\n", -1);
	}
	return 0;
}