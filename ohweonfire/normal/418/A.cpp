#include <stdio.h>
#include <cstdlib>
int main()
{
 	int n,k;
 	scanf("%d%d",&n,&k);
 	if(n<=k*2){puts("-1");return 0;}
 	printf("%d\n",n*k);
 	for(int i=0;i<n;i++)for(int j=i+1;j<i+k+1;j++)printf("%d %d\n",i+1,j%n+1);
	return 0;
}