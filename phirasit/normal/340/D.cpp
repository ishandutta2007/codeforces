#include <stdio.h>

int opt[100010];
int arr[100010];
int n;

int main() {
	int i,j;
	int ans;
	scanf("%d",&n);
	opt[0] = ans = 0;
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		int a = 0,b = ans;
		while(a < b) {
			int m = (a+b)/2 + 1;
			if(opt[m] > arr[i])
				b = m-1;
			else
				a = m;
		}
		if(b+1 > ans) ans = b+1;
		opt[b+1] = arr[i];
	}
	printf("%d\n",ans);
	return 0;
}