#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,a[105][105],b[105][105],c[100005][2],fla=0,flb=0;
void dfs(int dep,int x,int y,int xx,int yy)
{
	if(x==xx&&y==yy)
	{
		int nfla=1,nflb=1;
		for(int i=1;i<dep;i++)
			if(c[i][0]!=c[dep-i][0])
				nfla=0;
		for(int i=1;i<dep;i++)
			if(c[i][1]!=c[dep-i][1])
				nflb=0;
		fla|=nfla;
		flb|=nflb;
		return; 
	}
	if(x<xx)
	{
		c[dep][0]=a[x+1][y];
		c[dep][1]=b[x+1][y];
		dfs(dep+1,x+1,y,xx,yy);
	}
	if(y<yy)
	{
		c[dep][0]=a[x][y+1];
		c[dep][1]=b[x][y+1];
		dfs(dep+1,x,y+1,xx,yy);
	}
}
int getans(int x,int y,int xx,int yy)
{
	c[1][0]=a[x][y];
	c[1][1]=b[x][y];
	fla=0,flb=0;
	dfs(2,x,y,xx,yy);
	//printf("x=%d,y=%d,xx=%d,yy=%d,fl=%d,%d\n",x,y,xx,yy,fla,flb);
	if(fla!=flb)
	{
		int tp;
		printf("? %d %d %d %d\n",x,y,xx,yy);
		fflush(stdout);
		scanf("%d",&tp);
		printf("!\n");
		if(tp==fla)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					printf("%d",a[i][j]);
				printf("\n");
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					printf("%d",b[i][j]);
				printf("\n");
			}
		}
		return 1;
	}
	return 0;
}
int main()
{
	a[1][1]=1,a[n][n]=0;
	a[1][2]=0;
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=2)
		for(int j=1;j<=n;j+=2)
		{
			if(i==1&&j==1) continue;
			if(i==n&&j==n) continue;
			if(i>1)
			{
				printf("? %d %d %d %d\n",i-2,j,i,j);
				fflush(stdout);
				scanf("%d",&x);
				a[i][j]=a[i-2][j]^x^1;
			}
			else
			{
				printf("? %d %d %d %d\n",i,j-2,i,j);
				fflush(stdout);
				scanf("%d",&x);
				a[i][j]=a[i][j-2]^x^1;
			}
		}
	printf("? 1 1 2 2\n");
	fflush(stdout);
	scanf("%d",&x);
	a[2][2]=a[1][1]^x^1;
	for(int i=2;i<=n;i+=2)
		for(int j=2;j<=n;j+=2)
		{
			if(i==2&&j==2) continue;
			if(i>2)
			{
				printf("? %d %d %d %d\n",i-2,j,i,j);
				fflush(stdout);
				scanf("%d",&x);
				a[i][j]=a[i-2][j]^x^1;
			}
			else
			{
				printf("? %d %d %d %d\n",i,j-2,i,j);
				fflush(stdout);
				scanf("%d",&x);
				a[i][j]=a[i][j-2]^x^1;
			}
		}
	for(int i=1;i<=n;i+=2)
		for(int j=2;j<=n;j+=2)
		{
			if(i==1&&j==2) continue;
			if(i>1)
			{
				printf("? %d %d %d %d\n",i-2,j,i,j);
				fflush(stdout);
				scanf("%d",&x);
				a[i][j]=a[i-2][j]^x^1;
			}
			else
			{
				printf("? %d %d %d %d\n",i,j-2,i,j);
				fflush(stdout);
				scanf("%d",&x);
				a[i][j]=a[i][j-2]^x^1;
			}
		}
	printf("? 2 1 3 2\n");
	fflush(stdout);
	scanf("%d",&x);
	a[2][1]=a[3][2]^x^1;
	for(int i=2;i<=n;i+=2)
		for(int j=1;j<=n;j+=2)
		{
			if(i==2&&j==1) continue;
			if(i>2)
			{
				printf("? %d %d %d %d\n",i-2,j,i,j);
				fflush(stdout);
				scanf("%d",&x);
				a[i][j]=a[i-2][j]^x^1;
			}
			else
			{
				printf("? %d %d %d %d\n",i,j-2,i,j);
				fflush(stdout);
				scanf("%d",&x);
				a[i][j]=a[i][j-2]^x^1;
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if((i+j)%2) b[i][j]=a[i][j]^1;
			else b[i][j]=a[i][j];
		}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d",b[i][j]);
		printf("\n");
	}*/
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=i;k<=n;k++)
				for(int l=j;l<=n;l++)
					if(1)
					{
						int dis=abs(k-i)+abs(l-j);
						if(dis>=3&&dis<=5) 
						{
							if(getans(i,j,k,l)) return 0;
						}
					}
	return 0;
}