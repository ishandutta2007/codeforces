#include<bits/stdc++.h>
using namespace std;

int n,m,cnt,nw[200010],dep[200010],x,y,fa[200010],X,Y,ans[3][200010],ansn[3],hd[200010];
struct node{int to,next; bool bo;}e[1000010];
bool bo[200010];

int rev(int i) {return (i&1)?(i+1):(i-1);}

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x],0},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y],0},hd[y]=cnt;
}

void dfs(int x)
{
	bo[x]=1;
	for (int i=hd[x]; i; i=e[i].next) if (!bo[e[i].to]) 
		dep[e[i].to]=dep[x]+1,fa[e[i].to]=x,e[i].bo=e[rev(i)].bo=1,dfs(e[i].to);
}

void add(int i,int x,int y)
{
	ans[i][++ansn[i]]=x;
	while (x!=y) x=fa[x],ans[i][++ansn[i]]=x;
}

int ask(int x) {return fa[x]==x?x:fa[x]=ask(fa[x]);}

int main()
{
	scanf("%d%d",&n,&m),cnt=0;
	memset(hd,0,sizeof(hd));
	for (int i=1; i<=n; i++) fa[i]=i;
	for (int i=1; i<=m; i++) 
	{
		scanf("%d%d",&x,&y),addedge(x,y);
		fa[ask(x)]=ask(y);
	}
	int la=0;
	for (int i=1; i<=n; i++)
		if (fa[i]==i) 
		{
			if (la) addedge(la,i);
			la=i;
		}
	memset(fa,0,sizeof(fa));
	memset(bo,0,sizeof(bo)),dep[1]=0,dfs(1);
	for (int i=1; i<=cnt; i+=2) if (!e[i].bo)
	{
		x=e[i].to,y=e[rev(i)].to;
		if (dep[x]<dep[y]) swap(x,y);
		int xx=x;
		while (x!=y)
		{
			if (nw[x]) break;
			nw[x]=i,x=fa[x];
		}
		if (nw[x]&&x!=y)
		{
			puts("YES");
			X=e[nw[x]].to,Y=e[rev(nw[x])].to;
			if (dep[X]<dep[Y]) swap(X,Y);
			if (dep[y]<=dep[Y])
			{
				add(0,x,Y);
				add(1,X,x);
				for (int i=1; i<ansn[1]-i+1; i++) swap(ans[1][i],ans[1][ansn[1]-i+1]);
				ans[1][++ansn[1]]=Y;
				add(2,Y,y),add(2,xx,x);
				printf("%d ",ansn[2]);
				for (int i=ansn[2]; i; i--) printf("%d ",ans[2][i]); puts("");
				printf("%d ",ansn[1]);
				for (int i=1; i<=ansn[1]; i++) printf("%d ",ans[1][i]); puts("");
				printf("%d ",ansn[0]);
				for (int i=1; i<=ansn[0]; i++) printf("%d ",ans[0][i]); puts("");
			} else
			{
				add(0,x,y);
				ans[1][ansn[1]=1]=y,add(1,xx,x);
				add(2,y,Y),add(2,X,x);
				printf("%d ",ansn[2]);
				for (int i=ansn[2]; i; i--) printf("%d ",ans[2][i]); puts("");
				printf("%d ",ansn[1]);
				for (int i=ansn[1]; i; i--) printf("%d ",ans[1][i]); puts("");
				printf("%d ",ansn[0]);
				for (int i=1; i<=ansn[0]; i++) printf("%d ",ans[0][i]); puts("");
			}
			return 0;
		}
	}
	return puts("NO"),0;
}