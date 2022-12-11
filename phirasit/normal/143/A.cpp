#include <stdio.h>

int r1,r2,c1,c2,d1,d2;

int main() {
	int i,j,k,l;
	scanf("%d %d %d %d %d %d",&r1,&r2,&c1,&c2,&d1,&d2);
	for(i=1;i<10;i++) {
		for(j=1;j<10;j++) {
			for(k=1;k<10;k++) {
				for(l=1;l<10;l++) {
					if(i == j || i == k || i == l || j == k || j == l || k == l)
						continue;
					if(i + j != r1) continue;
					if(i + k != c1) continue;
					if(i + l != d1) continue;
					if(j + l != c2) continue;
					if(j + k != d2) continue;
					if(l + k != r2) continue;
					printf("%d %d\n%d %d\n",i,j,k,l);
					return 0;
				}
			}
		}
	}
	printf("-1\n");			
	return 0;
}