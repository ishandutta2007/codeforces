#include <stdio.h>
using namespace std;
int main()
{
 	int n,m;
 	scanf("%d%d",&n,&m);
 	if(n==1&&m==0){puts("1");return 0;}
 	if(n==1||m<n/2){puts("-1");return 0;}
 	int x=m-n/2+1;
 	printf("%d %d",x,x+x);
 	for(int i=1,j=1;j<=n-2;i++)
 	if(i!=x&&i!=x*2){printf(" %d",i);j++;}
 	return 0;
}