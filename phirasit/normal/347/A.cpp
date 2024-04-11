#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[110];
int n;

int main() {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	printf("%d ",arr[n-1]);
	for(i=1;i<n-1;i++)
		printf("%d ",arr[i]);
	printf("%d\n",arr[0]);
	return 0;
}