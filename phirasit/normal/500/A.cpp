#include <stdio.h>

#define N 30010

int pass[N];
int arr[N];
int n, t;

int main() {
	scanf("%d%d", &n, &t);
	for(int i = 1;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	arr[n] = n+1;
	for(int i = 1;i <= n;i+=arr[i]) {
		pass[i] = 1;
	}
	printf("%s\n", pass[t] ? "YES" : "NO");
	return 0;
}