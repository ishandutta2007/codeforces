#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000005],f[1000005][3][2];
void dfs(int x,int l,int r)
{
	if(l==r)
	{
		int ct=a[l*2]+a[l*2-1];
		f[x][ct][0]=!!ct;
		return;
	}
	int mid=(l+r)/2,ls=x*2,rs=x*2+1;
	dfs(ls,l,mid);
	dfs(rs,mid+1,r);
	int fl=(r-l+1!=2);
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
			for(int nw=0;nw<=2;nw++)
			{
				if(!nw) 
				{
					if(i==2||j==2) continue;
					for(int k=0;k<=1;k++)
						for(int l=0;l<=1;l++)
						{
							f[x][nw][k||l||i||j]=max(f[x][nw][k||l||i||j],
							f[ls][i][k]+f[rs][j][l]+(k||l||i||j)+((k||i)&&fl)+((l||j)&&fl));
						//	if(f[x][nw][k||l||i||j]>=0) printf("i=%d,j=%d,k=%d,l=%d\n",i,j,k,l); 
						}
				}
				if(nw==2) 
				{
					if(!i||!j) continue;
					for(int k=0;k<=1;k++)
						for(int l=0;l<=1;l++)
							f[x][nw][i==2||j==2||k||l]=max(f[x][nw][i==2||j==2||k||l],
							f[ls][i][k]+f[rs][j][l]+(i==2||j==2||k||l)+1+((k||i==2)&&fl)+((l||j==2)&&fl));
				}
				if(nw==1)
				{
					if((i==2&&j==2)||(!i&&!j)) continue;
					for(int k=0;k<=1;k++)
						for(int l=0;l<=1;l++)
						{
							if(j!=2&&i) f[x][nw][i==2||j||k||l]=max(f[x][nw][i==2||j||k||l],
							f[ls][i][k]+f[rs][j][l]+(i==2||j||k||l)+1+((k||i==2)&&fl)+((l||j)&&fl));
							if(i!=2&&j) f[x][nw][i||j==2||k||l]=max(f[x][nw][i||j==2||k||l],
							f[ls][i][k]+f[rs][j][l]+(i||j==2||k||l)+1+((k||i)&&fl)+((l||j==2)&&fl));
						}
				}
			}
/*	printf("x=%d,l=%d,r=%d,fl=%d\n",x,l,r,fl);
	for(int i=0;i<=2;i++)
		for(int j=0;j<=1;j++)
			printf("f[%d][%d]=%d\n",i,j,f[x][i][j]);*/
}
int main()
{
	memset(f,0xcf,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]=1;
	}
	if(!m)
	{
		printf("0\n");
		return 0;
	}
	dfs(1,1,(1<<(n-1)));
	/*if(f[1][0][0]>0)
	{
		printf("error");
		return 0;
	}*/
	int ans=0;
	for(int i=0;i<=2;i++)
		for(int j=0;j<=1;j++)
			ans=max(ans,f[1][i][j]+2);
	printf("%d",ans);
	return 0;
}