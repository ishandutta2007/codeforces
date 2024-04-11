#include<bits/stdc++.h>
using namespace std;

const int inf=1000000001;
const long long INF=1000000000000000000ll;
int a[2010][2010],n,m,x,y,d,pn[2][2010],s[2],val[2010],mii,id[2][2010],nw;
long long dis[2][2010],f[2][2010][2010],mif[2][2010][2010],po[2][2010][2010],mi,sum[2][2010][2010];
bool bo[2010];

bool cmp(int a,int b) {return dis[nw][a]<dis[nw][b];}

int main()
{
	scanf("%d%d%d%d",&n,&m,&s[0],&s[1]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) a[i][j]=inf;
	for (int i=1; i<=n; i++) scanf("%d",&val[i]);
	for (int i=1; i<=m; i++) scanf("%d%d%d",&x,&y,&d),a[x][y]=a[y][x]=min(a[x][y],d);
	for (int ovo=0; ovo<2; ovo++)
	{
		for (int i=1; i<=n; i++) dis[ovo][i]=INF,bo[i]=0;
		dis[ovo][s[ovo]]=0;
		for (int i=1; i<n; i++)
		{
			mi=INF;
			for (int j=1; j<=n; j++) 
				if (!bo[j]&&dis[ovo][j]<mi) mi=dis[ovo][j],mii=j;
			bo[mii]=1;
			for (int j=1; j<=n; j++)
				if (a[mii][j]!=inf&&dis[ovo][j]>dis[ovo][mii]+a[mii][j]) dis[ovo][j]=dis[ovo][mii]+a[mii][j];
		}
		for (int i=0; i<=n+1; i++) id[ovo][i]=i;
		nw=ovo,sort(id[ovo]+1,id[ovo]+1+n,cmp);
	}
	dis[0][n+1]=dis[1][n+1]=-1;
	dis[0][0]=dis[1][0]=-1;
	for (int ovo=0; ovo<2; ovo++)
		for (int i=0; i<=n; i++) 
			if (dis[ovo^1][id[ovo^1][i+1]]!=dis[ovo^1][id[ovo^1][i]]) 
			{
				pn[ovo][i]=0;
				for (int j=1; j<=n; j++)
					if (dis[ovo^1][id[ovo][j]]>dis[ovo^1][id[ovo^1][i]]) po[ovo][i][++pn[ovo][i]]=j;
				for (int j=1; j<=pn[ovo][i]; j++) sum[ovo][i][po[ovo][i][j]]+=val[id[ovo][po[ovo][i][j]]];
				for (int j=1; j<=n; j++) sum[ovo][i][j]+=sum[ovo][i][j-1];
			}
	for (int ovo=0; ovo<2; ovo++)
		for (int i=0; i<=n; i++) mif[ovo][i][n+1]=INF;
	for (int mi=n; mi>=0; mi--)
	{
		int i=mi;
		for (int j=n; j>mi; j--)
			for (int ovo=0; ovo<2; ovo++)
			{
				if (dis[ovo][id[ovo][i]]==dis[ovo][id[ovo][i+1]]) {mif[ovo][i][j]=mif[ovo][i][j+1]; continue;}
				if (dis[ovo^1][id[ovo^1][j]]==dis[ovo^1][id[ovo^1][j+1]]) {mif[ovo][i][j]=mif[ovo][i][j+1]; continue;}
				int I=id[ovo][i];
				if (!pn[ovo][j]||dis[ovo][I]>=dis[ovo][id[ovo][po[ovo][j][pn[ovo][j]]]]) 
				{
					f[ovo][i][j]=0,mif[ovo][i][j]=min(mif[ovo][i][j+1],-sum[ovo^1][i][j]);
					continue;
				}
				while (pn[ovo][j]>1&&dis[ovo][I]<dis[ovo][id[ovo][po[ovo][j][pn[ovo][j]-1]]]) pn[ovo][j]--;
				f[ovo][i][j]=-mif[ovo^1][j][po[ovo][j][pn[ovo][j]]]-sum[ovo][j][i];
				mif[ovo][i][j]=min(mif[ovo][i][j+1],f[ovo][i][j]-sum[ovo^1][i][j]);
			}
		int j=mi;
		for (int i=n; i>=mi; i--)
			for (int ovo=0; ovo<2; ovo++)
			{
				if (dis[ovo][id[ovo][i]]==dis[ovo][id[ovo][i+1]]) {mif[ovo][i][j]=mif[ovo][i][j+1]; continue;}
				if (dis[ovo^1][id[ovo^1][j]]==dis[ovo^1][id[ovo^1][j+1]]) {mif[ovo][i][j]=mif[ovo][i][j+1]; continue;}
				int I=id[ovo][i];
				if (!pn[ovo][j]||dis[ovo][I]>=dis[ovo][id[ovo][po[ovo][j][pn[ovo][j]]]]) 
				{
					f[ovo][i][j]=0,mif[ovo][i][j]=min(mif[ovo][i][j+1],-sum[ovo^1][i][j]);
					continue;
				}
				while (pn[ovo][j]>1&&dis[ovo][I]<dis[ovo][id[ovo][po[ovo][j][pn[ovo][j]-1]]]) pn[ovo][j]--;
				f[ovo][i][j]=-mif[ovo^1][j][po[ovo][j][pn[ovo][j]]]-sum[ovo][j][i];
				mif[ovo][i][j]=min(mif[ovo][i][j+1],f[ovo][i][j]-sum[ovo^1][i][j]);
			}
	}
	if (f[0][0][0]>0) puts("Break a heart"); else
	if (f[0][0][0]<0) puts("Cry"); else puts("Flowers");
	return 0;
}