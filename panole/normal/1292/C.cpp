#include<bits/stdc++.h>
using namespace std;

long long f[3010][3010];
int n,L[3010],R[3010],x,y,hd[3010],cnt,fa[3010],siz[3010];
vector<pair<int,int> > v[3010];
struct node{int to,next;}e[6010];

void getdfn(int x)
{
	L[x]=(++cnt),siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,getdfn(e[i].to),siz[x]+=siz[e[i].to];
	R[x]=cnt;
}

void dfs(int x,int fa,int dis,int y)
{
	if (dis&&x<y) v[dis].push_back(make_pair(x,y));
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x,dis+1,y);
}

int main()
{
	scanf("%d",&n),cnt=0;
	for (int i=1; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
		e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
	}
	cnt=0,fa[1]=0,getdfn(1);
	for (int i=1; i<=n; i++) dfs(i,0,0,i);
	for (int i=n; i; i--)
		for (int j=0,sz=v[i].size(); j<sz; j++)
		{
			x=v[i][j].first,y=v[i][j].second;
			int px=fa[x],py=fa[y],sx=siz[x],sy=siz[y];
			for (int k=hd[x]; k; k=e[k].next)
				if (e[k].to!=fa[x]&&L[e[k].to]<=L[y]&&R[e[k].to]>=L[y]) {px=e[k].to,sx=n-siz[px]; break;}
			for (int k=hd[y]; k; k=e[k].next)
				if (e[k].to!=fa[y]&&L[e[k].to]<=L[x]&&R[e[k].to]>=L[x]) {py=e[k].to,sy=n-siz[py]; break;}
			f[x][y]=0;
			for (int k=hd[x]; k; k=e[k].next)
				if (e[k].to!=px) f[x][y]=max(f[x][y],f[e[k].to][y]);
			for (int k=hd[y]; k; k=e[k].next)
				if (e[k].to!=py) f[x][y]=max(f[x][y],f[e[k].to][x]);
			f[x][y]+=1ll*sx*sy,f[y][x]=f[x][y];
		}
	long long ans=0;
	for (int i=1; i<=n; i++) 
		if (fa[i]) ans=max(ans,f[i][fa[i]]);
	printf("%I64d\n",ans);
	return 0;
}