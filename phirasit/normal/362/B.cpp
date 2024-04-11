/* B. Petya and Staircases */

#include <stdio.h>
#include <algorithm>

#define MX_N 3010

using namespace std;

int arr[MX_N];
int n,m;

int main() {
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+m);
	int check = 0;
	for(i=0;i<m-2;i++) {
		if(arr[i]+1 == arr[i+1] && arr[i+1]+1 == arr[i+2])
			check = 1;
	}
	if(arr[0] == 1 || arr[m-1] == n || check) {
		printf("NO\n");
	}else {
		printf("YES\n");
	}
	return 0;
}