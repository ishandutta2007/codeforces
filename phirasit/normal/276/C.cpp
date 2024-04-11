#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[200010];
int opt[200010];
int n,q;

int main() {
	int a,b;
	int i,j;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++) {
		scanf("%d",&arr[i]);
		opt[i] = 0;
	}
	for(i=0;i<q;i++) {
		scanf("%d %d",&a,&b);
		opt[a]++; opt[b+1]--;
	}
	for(i=1,j=0;i<=n;i++) {
		j += opt[i];
		opt[i] = j;
	}
	sort(arr+1,arr+n+1);
	sort(opt+1,opt+n+1);
	long long ans = 0;
	for(i=1;i<=n;i++) {
		ans += (long long)opt[i] * arr[i];
	}
	printf("%I64d\n",ans);
	return 0;
}