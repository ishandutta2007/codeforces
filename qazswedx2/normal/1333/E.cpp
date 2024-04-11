#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int table[4][4]={4,3,6,12,
				 7,5,9,15,
				 14,1,11,10,
				 13,8,16,2};
int n,a[1005][1005],ct=0;
int main()
{
	scanf("%d",&n);
	if(n<=2)
	{
		printf("-1");
		return 0;
	}
	if(n==3)
	{
		printf("1 2 4\n5 3 8\n9 6 7\n");
		return 0;
	}
	for(int i=n;i>4;i--)
		a[1][i]=++ct;
	for(int i=5;i<=n;i++)
		a[2][i]=++ct;
	for(int i=n;i>4;i--)
		a[3][i]=++ct;
	for(int i=5;i<=n;i++)
		a[4][i]=++ct;
	for(int i=n;i>5;i--)
	{
		if((n-i)%2==0)
		{
			for(int j=n;j>0;j--)
				a[i][j]=++ct;
		}
		else
		{
			for(int j=1;j<=n;j++)
				a[i][j]=++ct;
		}
	}
	if(n>=5)
	{
		if((n-5)%2==0)
		{
			for(int j=n;j>2;j--)
				a[5][j]=++ct;
			a[5][1]=++ct;
			a[5][2]=++ct;
		}
		else
		{
			a[5][1]=++ct;
			for(int j=3;j<=n;j++)
				a[5][j]=++ct;
			a[5][2]=++ct;
		}
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			a[i][j]=table[i-1][j-1]+ct;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}