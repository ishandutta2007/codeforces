#include <stdio.h>
#include <algorithm>

#define N 2010

using namespace std;

int arr[N];
int n, k;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	int ans = 0;
	for(int i = n-1;i >= 0;i-=k) {
		ans += 2*(arr[i]-1);
	}
	printf("%d\n", ans);
	return 0;
}