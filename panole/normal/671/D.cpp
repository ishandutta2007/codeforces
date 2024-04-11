#include<bits/stdc++.h>
using namespace std;

const long long inf=1000000000000000000ll;
int n,dep[300010],cnt,x,y,hd[300010],m,z,fa[300010],rt[300010];
struct node{int ls,rs; long long mi,laz;}t[7000010];
struct edg{int to,next;}e[600010];
vector<pair<int,int> > v[300010];

void pushdown(int i)
{
	if (!t[i].laz) return;
	if (t[i].ls) t[t[i].ls].mi+=t[i].laz,t[t[i].ls].laz+=t[i].laz;
	if (t[i].rs) t[t[i].rs].mi+=t[i].laz,t[t[i].rs].laz+=t[i].laz;
	t[i].laz=0;
}

void change(int i,int l,int r,int x,long long v)
{
	if (l==r) {t[i].mi=min(t[i].mi,v); return;}
	int mid=(l+r)>>1; pushdown(i);
	if (x<=mid) change(t[i].ls?t[i].ls:t[i].ls=(++cnt),l,mid,x,v);
	else change(t[i].rs?t[i].rs:t[i].rs=(++cnt),mid+1,r,x,v);
	t[i].mi=min(t[t[i].ls].mi,t[t[i].rs].mi);
}

long long query(int i,int l,int r,int ql,int qr)
{
	if (ql==l&&qr==r) return t[i].mi;
	int mid=(l+r)>>1; pushdown(i);
	if (qr<=mid) return t[i].ls?query(t[i].ls,l,mid,ql,qr):inf;
	if (ql>mid) return t[i].rs?query(t[i].rs,mid+1,r,ql,qr):inf;
	return min(t[i].ls?query(t[i].ls,l,mid,ql,mid):inf,t[i].rs?query(t[i].rs,mid+1,r,mid+1,qr):inf);
}

void merge(int i,int I,int l,int r)
{
	if (l==r) {t[i].mi=min(t[I].mi,t[i].mi); return;}
	int mid=(l+r)>>1; pushdown(i),pushdown(I);
	if (t[i].ls) {if (t[I].ls) merge(t[i].ls,t[I].ls,l,mid);} else t[i].ls=t[I].ls;
	if (t[i].rs) {if (t[I].rs) merge(t[i].rs,t[I].rs,mid+1,r);} else t[i].rs=t[I].rs;
	t[i].mi=min(t[t[i].ls].mi,t[t[i].rs].mi);
}

void addedge(int x,int y)
{
	e[++cnt]=(edg){y,hd[x]},hd[x]=cnt;
	e[++cnt]=(edg){x,hd[y]},hd[y]=cnt;
}

void init(int x)
{
	dep[x]=dep[fa[x]]+1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,init(e[i].to);
}

void dfs(int x)
{
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) 
		{
			dfs(e[i].to);
			if (!rt[x]) 
			{
				rt[x]=rt[e[i].to]; 
				if (query(rt[x],1,n,1,dep[x])>=inf/2) puts("-1"),exit(0);
			} else
			{
				long long nw;
				nw=query(rt[x],1,n,1,dep[x]);
				if (nw>=inf/2) puts("-1"),exit(0);
				t[rt[e[i].to]].laz+=nw,t[rt[e[i].to]].mi+=nw;
				nw=query(rt[e[i].to],1,n,1,dep[x])-nw;
				if (nw>=inf/2) puts("-1"),exit(0);
				t[rt[x]].laz+=nw,t[rt[x]].mi+=nw;
				merge(rt[x],rt[e[i].to],1,n);
			}
		}
	if (!rt[x]) 
	{
		rt[x]=(++cnt);
		for (int i=0,sz=v[x].size(); i<sz; i++)
			change(rt[x],1,n,v[x][i].first,v[x][i].second);
	} else
	{
		for (int i=0,sz=v[x].size(); i<sz; i++)
		{
			long long nw=query(rt[x],1,n,v[x][i].first+1,dep[x]);
			change(rt[x],1,n,v[x][i].first,nw+v[x][i].second);
		}
	}
}

int main()
{
	for (int i=0; i<=7000000; i++) t[i].ls=t[i].rs=0,t[i].mi=inf,t[i].laz=0;
	scanf("%d%d",&n,&m),cnt=0;
	if (n==1) return puts("0"),0;
	for (int i=1; i<n; i++) scanf("%d%d",&x,&y),addedge(x,y);
	fa[1]=0,dep[0]=0,init(1);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if (dep[x]<dep[y]) swap(x,y);
		if (x!=y) v[x].push_back(make_pair(dep[y],z));
	}
	cnt=0,dfs(1);
	printf("%I64d\n",query(rt[1],1,n,1,1));
	return 0;
}