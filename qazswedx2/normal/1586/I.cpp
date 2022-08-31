#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005][2];
char s[2005][2005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	if(n%2)
	{
		printf("NONE\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(s[i][j]!='.')
			{
				int u=(s[i][j]=='G'),p=-1;
				u^=min(min(i-1,j-1),min(n-i,n-j))&1;
				if((i+j)%2)
				{
					int nw=i-j;
					if(nw<0) nw=-nw;
					p=(nw+1)/2;
				}
				else
				{
					int nw=i+j;
					if(nw<=n) p=nw/2;
					else p=n+1-nw/2;
				}
				//printf("i=%d,j=%d,u=%d,p=%d\n",i,j,u,p);
				a[p][u]=1;
			}
	for(int i=1;i<=n/2;i++)
		if(a[i][0]&&a[i][1])
		{
			printf("NONE\n");
			return 0;
		}
	for(int i=1;i<=n/2;i++)
		if(!a[i][0]&&!a[i][1])
		{
			printf("MULTIPLE\n");
			return 0;
		}
	printf("UNIQUE\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int u=0,p=-1;
			u^=min(min(i-1,j-1),min(n-i,n-j))&1;
			if((i+j)%2)
			{
				int nw=i-j;
				if(nw<0) nw=-nw;
				p=(nw+1)/2;
			}
			else
			{
				int nw=i+j;
				if(nw<=n) p=nw/2;
				else p=n+1-nw/2;
			}
			u^=a[p][1];
			printf("%c",u?'G':'S');
		}
		printf("\n");
	}
	return 0;
}