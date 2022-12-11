#include <stdio.h>

int abs(int x) {
	if(x < 0) return -x;
	return x;
}
int main() {
	int i,j,k,ans;
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			scanf("%d",&k);
			if(k) {
				ans = abs(2-i) + abs(2-j);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}