#include <stdio.h>

#define MX_N 35

int r[MX_N],c[MX_N];
int n;

int main() {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			int k;
			scanf("%d",&k);
			r[i] += k;
			c[j] += k;
		}
	}
	int ans = 0;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			ans += (c[j] > r[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}