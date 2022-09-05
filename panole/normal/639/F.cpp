#include<bits/stdc++.h>
using namespace std;

const int N=300010;
int dfn[N],bel[N],hd[N],Hd[N],fa[N],cnt,x,y,R,n,m,q,low[N],sta[N],stp,tp[N],siz[N],T[N*3],EE[N][2],bcj[N],TT[N*6],TN,Bel[N],t[N],nn,Fa[N],Dfn[N];
struct node{int to,next;}e[N<<1],E[N<<1];
bool bo[N],Bo;

void Addedge(int x,int y)
{
	E[++cnt]=(node){y,Hd[x]},Hd[x]=cnt;
	E[++cnt]=(node){x,Hd[y]},Hd[y]=cnt;
}

void addedge(int x,int y) {e[++cnt]=(node){y,hd[x]},hd[x]=cnt;}
bool cmp(int x,int y) {return dfn[x]<dfn[y];}
int ask(int x) {return bcj[x]==x?x:bcj[x]=ask(bcj[x]);}

void tarjan(int x,int la)
{
	dfn[x]=low[x]=(++cnt),sta[++stp]=x,bo[x]=1;
	for (int i=Hd[x]; i; i=E[i].next) if (i!=(la^1))
	{
		if (!dfn[E[i].to]) tarjan(E[i].to,i),low[x]=min(low[x],low[E[i].to]);
		else if (bo[E[i].to]) low[x]=min(low[x],dfn[E[i].to]);
	}
	if (dfn[x]==low[x])
	{
		bel[x]=x,bo[x]=0;
		while (sta[stp]!=x) bel[sta[stp]]=x,bo[sta[stp]]=0,stp--;
		stp--;
	}
}

void dfs(int x)
{
	siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,dfs(e[i].to),siz[x]+=siz[e[i].to];
}

void Dfs(int x)
{
	dfn[x]=(++cnt); int ma=0,maa;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&siz[e[i].to]>ma) ma=siz[e[i].to],maa=e[i].to;
	if (!ma) return;
	tp[maa]=tp[x],Dfs(maa);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=maa) tp[e[i].to]=e[i].to,Dfs(e[i].to);
}

int lca(int x,int y)
{
	if (dfn[x]<dfn[y]) swap(x,y);
	while (tp[x]!=tp[y])
	{
		x=fa[tp[x]];
		if (dfn[x]<dfn[y]) swap(x,y);
	}
	return y;
}


int main()
{
	scanf("%d%d%d",&n,&m,&q),cnt=1,memset(Hd,0,sizeof(Hd));
	for (int i=1; i<=n; i++) bcj[i]=i;
	for (int i=1; i<=m; i++) scanf("%d%d",&x,&y),Addedge(x,y),bcj[ask(x)]=ask(y);
	cnt=stp=0,memset(bo,0,sizeof(bo));
	for (int i=1; i<=n; i++) if (!dfn[i]) tarjan(i,0);
	cnt=0,memset(hd,0,sizeof(hd));
	for (int i=1; i<=n; i++)
		for (int j=Hd[i]; j; j=E[j].next)
			if (bel[E[j].to]!=bel[i]) addedge(bel[i],bel[E[j].to]);
	memset(fa,0,sizeof(fa)),cnt=R=0;
	for (int i=1; i<=n; i++) if (!fa[i]) tp[i]=i,dfs(i),Dfs(i);
	memset(Hd,0,sizeof(Hd)),nn=n;
	for (int que=1; que<=q; que++)
	{
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++) scanf("%d",&T[i]),T[i]=bel[(T[i]+R-1)%nn+1],t[i]=T[i];
		for (int i=1; i<=m; i++) scanf("%d%d",&x,&y),EE[i][0]=bel[(x+R-1)%nn+1],EE[i][1]=bel[(y+R-1)%nn+1];
		for (int i=1; i<=m; i++) T[n+2*i-1]=EE[i][0],T[n+2*i]=EE[i][1];
		sort(T+1,T+1+n+2*m,cmp),cnt=1,sta[stp=1]=T[1],Fa[T[1]]=0,TT[TN=1]=T[1];
		for (int i=2; i<=n+2*m; i++) if (T[i]!=T[i-1])
		{
			if (ask(T[i])!=ask(T[i-1]))
			{
				for (int j=stp; j>1; j--) Fa[sta[j]]=sta[j-1];
				sta[stp=1]=T[i],Fa[T[i]]=0,TT[++TN]=T[i];
				continue;
			}
			x=T[i],y=lca(x,sta[stp]);
			while (stp>1&&siz[sta[stp-1]]<=siz[y]) Fa[sta[stp]]=sta[stp-1],stp--;
			if (siz[sta[stp]]<siz[y]) Fa[sta[stp]]=y,sta[stp]=y,Fa[y]=0,TT[++TN]=y;
			if (x!=y) sta[++stp]=x,Fa[x]=0,TT[++TN]=x;
		}
		Bo=1;
		for (int i=stp; i>1; i--) Fa[sta[i]]=sta[i-1];
		for (int i=1; i<=TN; i++) Dfn[TT[i]]=dfn[TT[i]],Hd[TT[i]]=0,dfn[TT[i]]=0,Bel[TT[i]]=bel[TT[i]];
		for (int i=1; i<=TN; i++) if (Fa[TT[i]]) Addedge(Fa[TT[i]],TT[i]);
		for (int i=1; i<=m; i++) Addedge(EE[i][0],EE[i][1]);
		for (int i=1; i<=TN; i++) if (!dfn[TT[i]]) tarjan(TT[i],0);
		for (int i=1; i<n; i++) if (bel[t[i]]!=bel[t[i+1]]) {Bo=0; break;}
		if (Bo) puts("YES"),R=(R+que)%nn; else puts("NO");
		for (int i=1; i<=TN; i++) bel[TT[i]]=Bel[TT[i]],dfn[TT[i]]=Dfn[TT[i]];
	}
	return 0;
}