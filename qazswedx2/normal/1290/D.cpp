#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,bl,sz,a[100005];
char ch;
int main()
{
	scanf("%d%d",&n,&m);
	/*if(n==m)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			printf("? %d\n",i);
			fflush(stdout);
			scanf("%s",s);
		}
	}*/
	if(n==1&&m==1)
	{
		printf("! 1\n");
		return 0;
	}
	if(m==1) m=2;
	bl=n/m*2;
	sz=n/bl;
	for(int i=1;i<=n;i++)
		a[i]=1;
	for(int i=1;i<bl;i++)
	{
		for(int j=1;j<=min(i,bl-i);j++)
		{
			printf("R\n");
			fflush(stdout);
			for(int k=j;k<=bl;k+=i)
			{
				for(int l=(k-1)*sz+1;l<=k*sz;l++)
				{
					printf("? %d\n",l);
					fflush(stdout);
					scanf(" %c",&ch);
					if(ch=='Y') a[l]=0;
				}
			}
		}
	}
	int tans=0;
	for(int i=1;i<=n;i++)
		tans+=a[i];
	printf("! %d\n",tans);
	return 0;
}