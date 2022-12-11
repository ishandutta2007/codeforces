#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[110];
int n;

int main() {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int mx = 0,a,b;
	for(i=0;i<n;i=b) {
		a = b = i;
		while(b < n && arr[a] == arr[b]) b++;
		if(b-a > mx)
			mx = b-a;
	}
	if(mx > n/2 + n%2) {
		printf("NO\n");
	}else {
		printf("YES\n");
	}
	return 0;
}