#include <stdio.h>

int n,k;

int main() {
	int i;
	scanf("%d %d",&n,&k);
	if(n == 1 && k == 1) {
		printf("a");
		return 0;
	}else if(k > n || k <= 1) {
		printf("-1\n");
		return 0;
	}
	for(i=0;i<n-k+2;i++)
		if(i%2 == 0) printf("a");
		else printf("b");
	for(i=0;i<k-2;i++)
		printf("%c",'c'+i);
	return 0;
}