#include<bits/stdc++.h>
using namespace std;

int n,m,k,ti[100010],val[100010],x,y,fa[100010],hd[100010],rt[100010],tot,z,siz[100010];
struct Edge{int to,next;}e[200010];
struct node{int ls,rs; long long mi,laz;}t[20000010];

void pushdown(int i)
{
	int L=t[i].ls,R=t[i].rs;
	if (!L) L=t[i].ls=(++tot);
	if (!R) R=t[i].rs=(++tot);
	if (t[i].laz<0) t[L].mi=-t[i].laz,t[L].laz=t[i].laz,t[R].mi=-t[i].laz,t[R].laz=t[i].laz; else 
	{
		t[L].mi+=t[i].laz,t[L].laz=(t[L].laz<0?t[L].laz-t[i].laz:t[L].laz+t[i].laz);
		t[R].mi+=t[i].laz,t[R].laz=(t[R].laz<0?t[R].laz-t[i].laz:t[R].laz+t[i].laz);
	}
	t[i].laz=0;
}

void add(int i,int l,int r,int ql,int qr,long long v)
{
	if (l==ql&&r==qr) 
	{
		t[i].mi+=v; 
		if (t[i].laz<0) t[i].laz-=v;
		else t[i].laz+=v;
		return;
	}
	pushdown(i);
	int mid=(l+r)>>1;
	if (qr<=mid) add(t[i].ls,l,mid,ql,qr,v); else
	if (ql>mid) add(t[i].rs,mid+1,r,ql,qr,v); else
	add(t[i].ls,l,mid,ql,mid,v),add(t[i].rs,mid+1,r,mid+1,qr,v);
	t[i].mi=min(t[t[i].ls].mi,t[t[i].rs].mi);
}

void change(int i,int l,int r,int ql,int qr,long long v)
{
	if (l==ql&&r==qr) 
	{
		t[i].mi=v,t[i].laz=-v; 
		return;
	}
	pushdown(i);
	int mid=(l+r)>>1;
	if (qr<=mid) change(t[i].ls,l,mid,ql,qr,v); else
	if (ql>mid) change(t[i].rs,mid+1,r,ql,qr,v); else
	change(t[i].ls,l,mid,ql,mid,v),change(t[i].rs,mid+1,r,mid+1,qr,v);
	t[i].mi=min(t[t[i].ls].mi,t[t[i].rs].mi);
}

void merge(int i,int I,int l,int r)
{
	if (l==r) {t[i].mi+=t[I].mi,t[i].laz=0; return;}
	int mid=(l+r)>>1;
	if (!t[I].ls)
	{
		if (t[I].laz<0) t[I].laz=-t[I].laz;
		if (t[i].laz<0) t[i].laz-=t[I].laz; else t[i].laz+=t[I].laz;
		t[i].mi+=t[I].laz;
	} else
	{
		pushdown(i),pushdown(I);
		merge(t[i].ls,t[I].ls,l,mid),merge(t[i].rs,t[I].rs,mid+1,r);
		t[i].mi=min(t[t[i].ls].mi,t[t[i].rs].mi);
	}
}

int find(int i,int l,int r,long long v)
{
	if (l==r||t[i].laz<0||!t[i].ls) return r;
	pushdown(i); int mid=(l+r)>>1;
	if (t[t[i].rs].mi<=v) return find(t[i].rs,mid+1,r,v);
	else return find(t[i].ls,l,mid,v);
}

long long query(int i,int l,int r,int x)
{
	if (l==r||!t[i].ls) return t[i].mi;
	if (t[i].laz<0) return -t[i].laz;
	int mid=(l+r)>>1;
	if (x<=mid) return query(t[i].ls,l,mid,x)+t[i].laz;
	else return query(t[i].rs,mid+1,r,x)+t[i].laz;
}

void dfs(int x)
{
	siz[x]=1;
	if (!hd[x])
	{
		rt[x]=(++tot);
		if (ti[x]) add(tot,1,k,ti[x],k,val[x]);
		return;
	}
	int ma=0,maa;
	for (int i=hd[x]; i; i=e[i].next)
	{
		dfs(e[i].to),siz[x]+=siz[e[i].to];
		if (siz[e[i].to]>ma) ma=siz[e[i].to],maa=e[i].to;
	}
	rt[x]=rt[maa];
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=maa) merge(rt[x],rt[e[i].to],1,k);
	if (ti[x])
	{
		add(rt[x],1,k,ti[x],ti[x],val[x]);
		long long nw=query(rt[x],1,k,ti[x]);
		change(rt[x],1,k,ti[x],find(rt[x],1,k,nw),nw);
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	memset(hd,0,sizeof(hd));
	for (int i=2; i<=n; i++) 
	{
		scanf("%d",&fa[i]);
		e[i]=(Edge){i,hd[fa[i]]},hd[fa[i]]=i;
	}
	memset(ti,0,sizeof(ti));
	for (int i=1; i<=m; i++) scanf("%d%d%d",&x,&y,&z),ti[x]=y,val[x]=z;
	tot=0,dfs(1),printf("%I64d\n",query(rt[1],1,k,k));
	return 0;
}