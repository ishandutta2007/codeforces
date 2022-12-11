#include <stdio.h>

int n,k;

int main() {
	int x,ans = 0;
	scanf("%d %d",&n,&k);
	while(n--) {
		int j=0;
		scanf("%d",&x);
		while(x) {
			if(x%10 == 4 || x%10 == 7)
				j++;
			x /= 10;
		}
		if(j <= k) ans++;
	}
	printf("%d\n",ans);
	return 0;
}