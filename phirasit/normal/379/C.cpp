#include <stdio.h>
#include <algorithm>

#define MX_N 300010

using namespace std;

typedef pair<int,int> pii;
pii arr[MX_N];
int ans[MX_N];
int n;

int main() {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i].first);
		arr[i].second = i;
	}
	sort(arr,arr+n);
	for(i=0;i<n;i++) {
		if(i > 0 && arr[i].first <= arr[i-1].first) {
			arr[i].first = arr[i-1].first + 1;
		}
		ans[arr[i].second] = arr[i].first;
	}
	for(i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}