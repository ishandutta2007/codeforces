#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,a[1005][1005],b[1005][1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+10;i++)
			for(int j=0;j<=m+10;j++)
				a[i][j]=b[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				char ch;
				scanf(" %c",&ch);
				if(ch=='X') a[i][j]=1;
			}
		int s=1;
		if(n%3==0) s=2;
		for(int i=s;i<=n;i+=3)
		{
			//printf("i=%d\n",i);
			for(int j=1;j<=m;j++)
				b[i][j]=1;
			b[i+1][1]=1;
			b[i+2][1]=1;
			if(a[i+1][2]||a[i+2][2])
			{
				b[i+1][1]=b[i+2][1]=0;
				b[i+1][2]=b[i+2][2]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]||b[i][j]) printf("X");
				else printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}