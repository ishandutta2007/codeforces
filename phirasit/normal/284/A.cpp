#include <stdio.h>

int p;

int main() {
	int ans = 0;
	int i,j,k;
	scanf("%d",&p);
	for(i=1;i<p;i++) { 
		k = i;
		for(j=0;j<p-2;j++) {
			if((k-1)%p == 0)
				break;
			k = (k*i)%p;
		}
		if(j >= p-2 && (k-1)%p == 0)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}