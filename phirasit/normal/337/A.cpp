#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[60];
int n,m;

int main() {
	int i,j,ans = 99999999;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+m);
	for(i=0;i<m-n+1;i++) {
		if(arr[i+n-1] - arr[i] < ans) {
			ans = arr[i+n-1] - arr[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}