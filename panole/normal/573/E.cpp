#include<bits/stdc++.h>
using namespace std;

long long del[100010];
int a[100010],n,rt,sta[100010],tp,tot,pp;
struct node{int fa,ch[2],siz; long long laz,val;}t[100010];

int clc(int x) {return t[t[x].fa].ch[1]==x;}
void upd(int x) {t[x].siz=t[t[x].ch[0]].siz+t[t[x].ch[1]].siz+1;}

void pushdown(int x)
{
	if (!t[x].laz) return;
	if (t[x].ch[0])
	{
		t[t[x].ch[0]].laz+=t[x].laz;
		t[t[x].ch[0]].val+=t[x].laz;
	}
	if (t[x].ch[1])
	{
		t[t[x].ch[1]].laz+=t[x].laz;
		t[t[x].ch[1]].val+=t[x].laz;
	}
	t[x].laz=0;
}

void rotate(int x)
{
	int f=t[x].fa,g=t[f].fa,F=clc(x);
	if (rt==f) rt=x; else t[g].ch[clc(f)]=x;
	t[x].fa=g,t[t[x].ch[F^1]].fa=f;
	t[f].ch[F]=t[x].ch[F^1];
	t[x].ch[F^1]=f,t[f].fa=x,upd(f);
}

void splay(int x)
{
	int X=x; tp=0;
	while (X) sta[++tp]=X,X=t[X].fa;
	for (int i=tp; i; i--) pushdown(sta[i]);
	for (int f=t[x].fa; f; rotate(x),f=t[x].fa)
		if (f!=rt) rotate(clc(f)==clc(x)?f:x);
	upd(x);
}

int gnode(int x,long long v)
{
	t[++tot]=(node){x,{0,0},1,0ll,v};
	return tot;
}

void ins(int x,int s,long long v)
{
	pushdown(x);
	if (s<=t[t[x].ch[0]].siz)
	{
		if (!t[x].ch[0]) t[x].ch[0]=gnode(x,v),upd(x);
		else ins(t[x].ch[0],s,v),upd(x);
	} else
	{
		if (!t[x].ch[1]) t[x].ch[1]=gnode(x,v),upd(x);
		else ins(t[x].ch[1],s-t[t[x].ch[0]].siz-1,v),upd(x);
	}
}

void ins(int s,long long v) {ins(rt,s,v),splay(tot);}

int find(int x,int l,int r,int v)
{
	pushdown(x),pp=x;
	if (t[x].val<=1ll*(l+t[t[x].ch[0]].siz)*v)
	{
		if (t[x].ch[0]) return find(t[x].ch[0],l,l+t[t[x].ch[0]].siz-1,v);
		else return l-1;
	} else
	{
		if (t[x].ch[1]) return find(t[x].ch[1],r-t[t[x].ch[1]].siz+1,r,v);
		else return r;
	}
}

void dfs(int x,int l,int r)
{
	pushdown(x);
	del[l+t[t[x].ch[0]].siz]=t[x].val;
	if (t[x].ch[0]) dfs(t[x].ch[0],l,l+t[t[x].ch[0]].siz-1);
	if (t[x].ch[1]) dfs(t[x].ch[1],r-t[t[x].ch[1]].siz+1,r);
}

int main()
{
	scanf("%d",&n),rt=1,t[0].siz=0,tot=1;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	t[1]=(node){0,{0,0},1,0ll,1ll*a[1]};
	for (int nw,i=2; i<=n; i++)
	{
		nw=find(rt,1,i-1,a[i]),splay(pp),ins(nw,1ll*(nw+1)*a[i]);
		if (nw=t[rt].ch[1]) t[nw].laz+=a[i],t[nw].val+=a[i];
	}
	dfs(rt,1,n);
	long long ans=0,nw=0;
	for (int i=1; i<=n; i++) nw+=del[i],ans=max(ans,nw);
	printf("%I64d\n",ans);
	return 0;
}