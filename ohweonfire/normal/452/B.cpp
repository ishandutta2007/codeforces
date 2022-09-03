#include <stdio.h>
#include <cmath>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if(n==0)
		printf("0 %d\n0 %d\n0 %d\n0 %d\n",1,m,0,m-1);
	else if(m==0)
		printf("%d 0\n%d 0\n%d 0\n%d 0\n",1,n,0,n-1);
	else
	{
		if(n>m)
		{
			double j1=sqrt(n*n+m*m)*2+n;
			double j2=sqrt(n*n+m*m)+sqrt(n*n+(m-1)*(m-1))*2;
			if(j1>j2)
				printf("0 0\n%d %d\n0 %d\n%d 0\n",n,m,m,n);
			else
				printf("0 1\n%d %d\n0 0\n%d %d\n",n,m,n,m-1);
		}
		else
		{
			double j1=sqrt(m*m+n*n)*2+m;
			double j2=sqrt(n*n+m*m)+sqrt(m*m+(n-1)*(n-1))*2;
			if(j1>j2)
				printf("0 0\n%d %d\n%d 0\n0 %d\n",n,m,n,m);
			else
				printf("1 0\n%d %d\n0 0\n%d %d\n",n,m,n-1,m);
		}
	}
	return 0;
}