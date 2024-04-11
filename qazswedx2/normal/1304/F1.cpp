#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,a[55][100005],f[55][100005],nxt[55][100005];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]+=a[i][j-1];
		}
	for(int j=1;j<=m-k+1;j++)
	{
		f[1][j]=a[1][j+k-1]-a[1][j-1]+a[2][j+k-1]-a[2][j-1];
		//printf("i=%d,j=%d,f=%d\n",1,j,f[1][j]);
	}
	for(int i=2;i<=n;i++)
	{
		nxt[i][m-k+1]=f[i-1][m-k+1];
		for(int j=m-k;j;j--)
		{
			if(nxt[i][j+1]>f[i-1][j])
				nxt[i][j]=nxt[i][j+1];
			else nxt[i][j]=f[i-1][j];
		}
		int nw=0;
		for(int j=1;j<=m-k+1;j++)
		{
			if(j-k>=1) nw=max(nw,f[i-1][j-k]);
			f[i][j]=max(nxt[i][j+k],nw)+a[i][j+k-1]-a[i][j-1]+a[i+1][j+k-1]-a[i+1][j-1];
			//printf("f=%d\n",f[i][j]);
			for(int kk=max(1,j-k+1);kk<=j;kk++)
				f[i][j]=max(f[i][j],f[i-1][kk]+a[i+1][j+k-1]-a[i+1][j-1]+a[i][j+k-1]-a[i][kk+k-1]);
		//	printf("f=%d\n",f[i][j]);
			for(int kk=j+1;kk<=min(j+k-1,m-k+1);kk++)
				f[i][j]=max(f[i][j],f[i-1][kk]+a[i+1][j+k-1]-a[i+1][j-1]+a[i][kk-1]-a[i][j-1]);
		//	printf("i=%d,j=%d,f=%d\n",i,j,f[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=m-k+1;i++)
		ans=max(ans,f[n][i]);
	printf("%d",ans);
	return 0;
}