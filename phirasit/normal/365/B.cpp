#include <stdio.h>
#define MX_N 100010

int opt[MX_N];
int arr[MX_N];
int n;

int main() {
	int i,j;
	scanf("%d",&n);
	int mx = 0;
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		if(i >= 2 && arr[i] == arr[i-1] + arr[i-2])
			opt[i] = opt[i-1] + 1;
		else
			opt[i] = 2;
		if(opt[i] > mx) mx = opt[i];
	}
	if(n == 1)
		printf("1\n");
	else
		printf("%d",mx);
	return 0;
}