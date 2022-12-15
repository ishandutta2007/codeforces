#include<bits/stdc++.h>
using namespace std;
 
bool bo[200010];
int n,x,y,hd[200010],k,q[200010],qn,l,r,cnt,la[200010],col[200010],mxd[200010],dep[200010];
struct node{int to,next;}e[400010];
 
void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
}
 
void getcol2(int x,int fa)
{
	for (int i=hd[x]; i ;i=e[i].next)
		if (e[i].to!=fa) col[e[i].to]=3-col[x],getcol2(e[i].to,x);
}
 
void dfs(int x,int fa)
{
	mxd[x]=dep[x]=dep[fa]+1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x),mxd[x]=max(mxd[x],mxd[e[i].to]);
}
 
void dfs1(int x,int fa)
{
	col[x]=(col[fa]==k?1:col[fa]+1);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa) dfs1(e[i].to,x);
}
 
void dfs2(int x,int fa)
{
	col[x]=(col[fa]==1?k:col[fa]-1);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa) dfs2(e[i].to,x);
}
 
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1; i<n; i++) scanf("%d%d",&x,&y),addedge(x,y);
	if (k==2)
	{
		col[1]=1,getcol2(1,0);
		puts("Yes");
		for (int i=1; i<=n; i++) printf("%d ",col[i]); puts("");
		return 0;
	}
	q[l=r=1]=1,memset(bo,0,sizeof(bo)),bo[1]=1;
	while (l<=r)
	{
		x=q[l++];
		for (int i=hd[x]; i; i=e[i].next)
			if (!bo[e[i].to]) q[++r]=e[i].to,bo[e[i].to]=1;
	}
	q[1]=q[r],l=r=1,memset(bo,0,sizeof(bo)),bo[q[1]]=1,la[q[1]]=0;
	while (l<=r)
	{
		x=q[l++];
		for (int i=hd[x]; i; i=e[i].next)
			if (!bo[e[i].to]) q[++r]=e[i].to,bo[e[i].to]=1,la[e[i].to]=x;
	}
	int nw=q[1];
	q[qn=1]=q[r];
	while (la[q[qn]]) q[qn+1]=la[q[qn]],qn++;
	memset(bo,0,sizeof(bo));
	for (int i=1; i<=qn; i++) bo[q[i]]=1,col[q[i]]=i%k+1;
	for (int i=1; i<=qn; i++)
	{
		mxd[q[i]]=0;
		for (int j=hd[q[i]]; j; j=e[j].next)
			if (!bo[e[j].to]) 
			{
				dfs(e[j].to,q[i]);
				mxd[q[i]]=max(mxd[q[i]],mxd[e[j].to]);
			}
		if (mxd[q[i]]&&mxd[q[i]]+i>=k&&mxd[q[i]]+(qn-i+1)>=k) return puts("No"),0;
		if (mxd[q[i]]+i>=k)
		{
			for (int j=hd[q[i]]; j; j=e[j].next)
				if (!bo[e[j].to]) dfs1(e[j].to,q[i]);
		} else
		{
			for (int j=hd[q[i]]; j; j=e[j].next)
				if (!bo[e[j].to]) dfs2(e[j].to,q[i]);
		}
	}
	puts("Yes");
	for (int i=1; i<=n; i++) printf("%d ",col[i]); puts("");
	return 0;
}