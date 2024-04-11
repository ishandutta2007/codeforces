#include<bits/stdc++.h>
using namespace std;

int fa[1010],f[1010][1010],siz[1010],las[1010][1010],n,hd[1010],cnt,val[1010],rt,mi,ma,x,y,v[1010],col[1010],t[1010],tn;
struct node{int to,next;}e[2020];

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
}

void dfs(int x,int fa)
{
	siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x),siz[x]+=siz[e[i].to];
}

void Dfs(int x)
{
	v[x]=val[++cnt];
	for (int i=hd[x]; i; i=e[i].next) 
		if (e[i].to!=fa[x]) fa[e[i].to]=x,Dfs(e[i].to);
}

int main()
{
	scanf("%d",&n),cnt=0,memset(hd,0,sizeof(hd));
	for (int i=1; i<n; i++) scanf("%d%d",&x,&y),addedge(x,y);
	dfs(1,0),mi=n+1;
	for (int i=1; i<=n; i++)
	{
		ma=n-siz[i];
		for (int j=hd[i]; j; j=e[j].next)
			if (siz[e[j].to]<siz[i]) ma=max(ma,siz[e[j].to]);
		if (ma<mi) mi=ma,rt=i;
	}
	tn=0;
	for (int i=hd[rt]; i; i=e[i].next) t[++tn]=e[i].to;
	for (int i=hd[rt]; i; i=e[i].next)
		if (siz[e[i].to]>siz[rt]) siz[e[i].to]=n-siz[rt];
	memset(f,0,sizeof(f)),f[0][0]=1;
	for (int i=1; i<=tn; i++)
	{
		for (int j=0; j<=n; j++)
			if (f[i-1][j]) 
			{
				f[i][j]=1,las[i][j]=0;
				f[i][siz[t[i]]+j]=1,las[i][siz[t[i]]+j]=1;
			}
	}
	int nw=0;
	for (int j=0; j<=n; j++) 
		if (f[tn][j]&&(j+1)*(n-j)>(2*n*n)/9) {nw=j; break;}
	for (int i=1; i<=nw; i++) val[i]=i;
	for (int i=nw+1; i<n; i++) val[i]=(i-nw)*(nw+1);
	for (int i=tn; i; i--)
	{
		col[t[i]]=las[i][nw];
		if (las[i][nw]) nw-=siz[t[i]];
	}
	v[rt]=cnt=0;
	for (int i=1; i<=tn; i++) if (col[t[i]]) fa[t[i]]=rt,Dfs(t[i]);
	for (int i=1; i<=tn; i++) if (!col[t[i]]) fa[t[i]]=rt,Dfs(t[i]);
	for (int i=1; i<=n; i++) if (i!=rt) printf("%d %d %d\n",i,fa[i],v[i]-v[fa[i]]);
	return 0;
}