#include <stdio.h>
#include <algorithm>

#define N 300010

using namespace std;

int arr[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	
	long long ans = 0;
	int cnt = n;
	for(int i = n-1;i>=0;i--) {
		ans += (long long)cnt * arr[i];
		if(i < n-1) {
			cnt--;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}