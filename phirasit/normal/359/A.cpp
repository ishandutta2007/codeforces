#include <stdio.h>

int n,m,x;

int main() {
	int i,j;
	int ch = 0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d",&x);
			if(x) 
				if(i == 0 || j == 0 || i == n-1 || j == m-1)
					ch = 1;
		}
	}
	if(ch) printf("2\n");
	else printf("4\n");
	return 0;
}