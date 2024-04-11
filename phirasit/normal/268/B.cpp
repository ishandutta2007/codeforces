#include <stdio.h>

int n;

int main() {
	int i,ans = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		ans += (n-i-1)*(i+1) + 1;
	}
	printf("%d\n",ans);
	return 0;
}