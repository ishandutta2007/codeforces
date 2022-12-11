#include <stdio.h>

int n,m;

int main() {
	int i,j,ans = 0;
	scanf("%d %d",&n,&m);
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++) 
			if(i*i+j == n && i+j*j == m)
				ans++;
	printf("%d\n",ans);
	return 0;
}