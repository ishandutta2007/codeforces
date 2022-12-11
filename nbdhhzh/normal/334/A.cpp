#include<cstring>
#include<cstdio>
using namespace std;
int i,j,n;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		for (j=(i-1)*(n/2)+1;j<=i*(n/2);j++)
			printf("%d ",j);
		for (j=i*(n/2);j>=(i-1)*(n/2)+1;j--)
			printf("%d ",n*n-j+1);
		printf("\n");
	}
}