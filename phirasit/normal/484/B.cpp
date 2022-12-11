#include <stdio.h>

#define INF (-1u/2)
#define N 1000010

int arr[2 * N], last[2 * N];
int n;

int ans = INF;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		int val;
		scanf("%d", &val);
		arr[val] = 1;
	}
	for(int i = 1;i < 2 * N;i++) {
		if(i == 1) {
			last[i] = -1;
		}else {
			last[i] = last[i - 1];
		}
		if(arr[i]) {
			last[i] = i;
		}
	}
	int mx = 0;
	for(int i = 1;i < N;i++) {
		if(arr[i]) {
			for(int j = i + i;j < 2 * N;j += i) {
				if(last[j - 1] % i > mx) {
					mx = last[j - 1] % i;
				}
			}
		}
	}
	printf("%d\n", mx);
	return 0;
}