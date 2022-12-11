#include <stdio.h>

int n,m;

int main() {
	int i,l,j,k;
	scanf("%d %d",&n,&m);
	j = k = 0;
	for(i=1;i<=n;i++) {
		scanf("%d",&l);
		if(l == 1)
			j++;
		else
			k++;
	}
	while(m--) {
		scanf("%d %d",&i,&l);
		i = l-i+1;
		if(i%2 == 0 && j >= i/2 && k >= i/2)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}