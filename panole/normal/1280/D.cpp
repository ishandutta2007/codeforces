#include<bits/stdc++.h>
using namespace std;

long long ans1,ans2;
int T,n,siz[3010],fa[3010],hd[3010],cnt;
pair<int,long long> f[3010][3010],ff[3010];
long long v[3010];
struct node{int to,next;}e[6010];

void dfs(int x)
{
	bool bo=0;
	siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x])
		{
			fa[e[i].to]=x,dfs(e[i].to);
			if (!bo)
			{
				bo=1,f[x][1]=make_pair(-1,-1);
				for (int j=1; j<=siz[e[i].to]; j++) 
				{
					f[x][j]=max(f[x][j],make_pair(f[e[i].to][j].first,f[e[i].to][j].second+v[x]));
					f[x][j+1]=make_pair(f[e[i].to][j].first+(f[e[i].to][j].second>0),v[x]);
				}
				siz[x]+=siz[e[i].to];
			} else
			{
				for (int j=1; j<=siz[x]+siz[e[i].to]; j++) ff[j]=make_pair(-1,-1);
				for (int j=1; j<=siz[x]; j++)
					for (int k=1; k<=siz[e[i].to]; k++)
						ff[j+k]=max(ff[j+k],make_pair(f[x][j].first+f[e[i].to][k].first+(f[e[i].to][k].second>0),f[x][j].second)),
						ff[j+k-1]=max(ff[j+k-1],make_pair(f[x][j].first+f[e[i].to][k].first,f[x][j].second+f[e[i].to][k].second));
				siz[x]+=siz[e[i].to];
				for (int j=1; j<=siz[x]; j++) f[x][j]=ff[j];
			}
		}
	if (!bo) f[x][1]=make_pair(0,v[x]);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int m;
		scanf("%d%d",&n,&m),cnt=0;
		for (int i=1; i<=n; i++) scanf("%I64d",&v[i]);
		for (int i=1; i<=n; i++) 
		{
			int w; scanf("%d",&w);
			v[i]=w-v[i];
		}
		for (int i=1; i<=n; i++) hd[i]=fa[i]=0;
		for (int i=1; i<n; i++) 
		{
			int x,y; scanf("%d%d",&x,&y);
			e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
			e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
		}
		dfs(1),printf("%d\n",f[1][m].first+(f[1][m].second>0));
	}
	return 0;
}