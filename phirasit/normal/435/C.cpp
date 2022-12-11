#include <stdio.h>

#define N 1010

int arr[N];
int pos[N];
int n;

int main() {
	scanf("%d",&n);
	int sum = 0;
	for(int i = 0;i < n;i++) {
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	pos[0] = 0;
	int mn = 0,mx = 0;
	for(int i = 1;i <= n;i++) {
		pos[i] = pos[i-1] + (i%2?-1:1) * (arr[i-1]-1);
		if(pos[i] < mn) mn = pos[i];
		if(pos[i] > mx) mx = pos[i];
	}
	for(int i = 0;i <= mx-mn;i++) {
		for(int j = 0;j < n;j++) {
			for(int k = 0;k < arr[j];k++) {
				if(pos[j] - mn + (j%2?1:-1) * k == i) {
					printf("%c",j%2?'\\':'/');
				}else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}