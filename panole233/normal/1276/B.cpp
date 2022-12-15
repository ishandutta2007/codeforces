#include<bits/stdc++.h>
using namespace std;

bool bo[200010];
int T,n,m,hd[200010],a,b,x,y,fa[200010],cnt,siz[200010],L[200010],R[200010],p[200010],Fa[200010];
struct node{int to,next;}e[1000010];

int ask(int x) {return fa[x]==x?x:fa[x]=ask(fa[x]);}

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x]},hd[x]=cnt;	
	e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
}

void dfs(int x)
{
	bo[x]=1;
	siz[x]=1,L[x]=(++cnt),p[cnt]=x;
	for (int i=hd[x]; i; i=e[i].next)
		if (!bo[e[i].to]) dfs(e[i].to),siz[x]+=siz[e[i].to],Fa[e[i].to]=x;
	R[x]=cnt;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&n,&m,&a,&b),cnt=0;
		for (int i=1; i<=n; i++) hd[i]=0,bo[i]=0,fa[i]=i,Fa[i]=0;
		for (int i=1; i<=m; i++) 
		{
			scanf("%d%d",&x,&y),addedge(x,y);
			if (x!=b&&y!=b) fa[ask(x)]=ask(y);
		}
		cnt=0,dfs(a);
		int ans=0,anss=0;
		for (int i=hd[a]; i; i=e[i].next)
			if (L[e[i].to]<=L[b]&&R[e[i].to]>=L[b]&&Fa[e[i].to]==a) ans=n-siz[e[i].to];
		for (int i=L[b]+1; i<=R[b]; i++)
			if (ask(p[i])!=ask(a)) anss++;
		printf("%I64d\n",1ll*(ans-1)*(anss));
	}
	return 0;
}

//sigma max(mid,nw)>=mid*mid