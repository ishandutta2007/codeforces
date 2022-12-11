#include <stdio.h>
#include <algorithm>
#define MX_N 110

using namespace std;

int n,d,m;
int arr[MX_N];

int main() {
	int i,j;
	scanf("%d %d",&n,&d);
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	sort(arr,arr+n);
	int ans = 0;
	for(i=0;i<m && i < n;i++)
		ans += arr[i];
	if(m > n) ans -= (m-n)*d;
	printf("%d\n",ans);
	return 0;
}