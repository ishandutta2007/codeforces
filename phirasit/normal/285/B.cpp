#include <stdio.h>

int p[100010];
int use[100010];
int n,k;

int main() {
	int i,j,a,b;
	scanf("%d %d %d",&n,&a,&b);
	for(i=1;i<=n;i++) {
		scanf("%d",&p[i]);
	}
	i = a;
	for(j=0;i != b;j++) {
		if(use[i]) break;
		use[i] = 1;
		i = p[i];
	}
	if(i != b)
		printf("-1\n");
	else
		printf("%d\n",j);
	return 0;
}