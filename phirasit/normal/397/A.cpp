#include <stdio.h>

#define N 110

int arr[N], tmp[N];
int n;

int main() {
	scanf("%d", &n);
	int x, y;
	for(int i = 0;i < n;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(i == 0) {
			x = a;
			y = b;
		}else {
			for(int j = a;j <= b-1;j++) {
				arr[j] = 1;
			}
			for(int j = a+1;j <= b;j++) {
				tmp[j] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = x;i <= y;i++) {
		if(arr[i] == 0) {
			int cnt = 0;
			for(int j = i+1;j<=100 && j <= y;j++) {
				i = j;
				if(tmp[j]) {
					i--;
					break;
				}
				cnt++;
			}
			ans += cnt;
		}
	}
	printf("%d\n", ans);
	return 0;
}