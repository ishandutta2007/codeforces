#include<bits/stdc++.h>
using namespace std;

const int L=0,R=1000000;
int n,q,a[500010],x,y;
struct node{int l,r,laz,mi,num;}t[4000010];

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].mi=t[i].num=0,t[i].laz=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}

void pushdown(int i)
{
	if (!t[i].laz) return;
	t[i<<1].mi+=t[i].laz,t[i<<1].laz+=t[i].laz;
	t[i<<1|1].mi+=t[i].laz,t[i<<1|1].laz+=t[i].laz;
	t[i].laz=0;
}

void add(int i,int l,int r,int v)
{
	if (t[i].l==l&&t[i].r==r) {t[i].mi+=v,t[i].laz+=v; return;}
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) add(i<<1,l,r,v); else
	if (l>mid) add(i<<1|1,l,r,v); else
	add(i<<1,l,mid,v),add(i<<1|1,mid+1,r,v);
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
	t[i].num=(t[i<<1].mi==t[i].mi)*t[i<<1].num+(t[i<<1|1].mi==t[i].mi)*t[i<<1|1].num;
}

void change(int i,int x)
{
	if (t[i].l==t[i].r) {t[i].num^=1; return;}
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	change(i<<1|(x>mid),x);
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
	t[i].num=(t[i<<1].mi==t[i].mi)*t[i<<1].num+(t[i<<1|1].mi==t[i].mi)*t[i<<1|1].num;
}

int main()
{
	scanf("%d%d",&n,&q),a[0]=1000001,a[n+1]=0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	build(1,L,R);
	for (int i=0; i<=n; i++)
		if (a[i]!=a[i+1])
		{
			if (a[i]<a[i+1]) add(1,a[i],a[i+1]-1,1);
			else add(1,a[i+1],a[i]-1,1);
		}
	for (int i=1; i<=n; i++) change(1,a[i]);
	while (q--)
	{
		scanf("%d%d",&x,&y),change(1,a[x]);
		if (a[x-1]!=a[x])
		{
			if (a[x]<a[x-1]) add(1,a[x],a[x-1]-1,-1);
			else add(1,a[x-1],a[x]-1,-1);
		}
		if (a[x+1]!=a[x])
		{
			if (a[x]<a[x+1]) add(1,a[x],a[x+1]-1,-1);
			else add(1,a[x+1],a[x]-1,-1);
		}
		a[x]=y,change(1,a[x]);
		if (a[x-1]!=a[x])
		{
			if (a[x]<a[x-1]) add(1,a[x],a[x-1]-1,1);
			else add(1,a[x-1],a[x]-1,1);
		}
		if (a[x+1]!=a[x])
		{
			if (a[x]<a[x+1]) add(1,a[x],a[x+1]-1,1);
			else add(1,a[x+1],a[x]-1,1);
		}
		printf("%d\n",t[1].num);
	}
	return 0;
}