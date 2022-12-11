#include <stdio.h>

#define N 1000010

using namespace std;

int pre[N];
int arr[N];
int n,ans = 0;

int main() {
	scanf("%d",&n);
	pre[0] = 0;
	for(int i=1;i<=n;i++) {
		pre[i] = i ^ pre[i-1];
	}
	for(int i=1;i<=n;i++) {
		if((n/i)%2 == 1) {
			ans ^= pre[i-1];
		}
		ans ^= pre[n%i];
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",&arr[i]);
		ans ^= arr[i];
	}
	printf("%d\n",ans);
	return 0;
}