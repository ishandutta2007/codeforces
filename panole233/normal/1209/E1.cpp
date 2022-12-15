#include<bits/stdc++.h>
using namespace std;

int T,n,m,a[13][2010],f[13][1<<12|3],b[13][13],g[13][1<<12|3];
pair<int,int> ma[2010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++) scanf("%d",&a[i][j]);
		if (n<m)
		{
			for (int i=1; i<=m; i++)
			{
				ma[i]=make_pair(0,i);
				for (int j=1; j<=n; j++) 
					if (a[j][i]>ma[i].first) ma[i].first=a[j][i];
			}
			sort(ma+1,ma+1+m);
			for (int i=m; i>=m-n+1; i--)
				for (int j=1; j<=n; j++) b[m-i+1][j]=a[j][ma[i].second];
			m=n;
		} else
		{
			for (int i=1; i<=m; i++)
				for (int j=1; j<=n; j++) b[i][j]=a[j][i];
		}
		for (int i=1; i<=m; i++)
		{
			for (int j=0; j<(1<<n); j++)
			{
				g[i][j]=0;
				for (int nw,l=1; l<=n; l++)
				{
					nw=0;
					for (int k=1; k<=n; k++) 
						if (j>>(k-1)&1) nw+=b[i][k];
					if (nw>g[i][j]) g[i][j]=nw;
					for (int k=0; k<n; k++) b[i][k]=b[i][k+1];
					b[i][n]=b[i][0];
				}
			}
		}
		memset(f,0,sizeof(f));
		for (int i=1; i<=m; i++)
			for (int j=0; j<(1<<n); j++)
			{
				f[i][j]=max(f[i][j],f[i-1][j]);
				for (int J=j^((1<<n)-1),k=J; k; k=(k-1)&J)
					f[i][j|k]=max(f[i][j|k],f[i-1][j]+g[i][k]);
			}
		printf("%d\n",f[m][(1<<n)-1]);
	}
	return 0;
}