#include<bits/stdc++.h>
using namespace std;

struct node
{
	int l,r,val;
}t[800010];

int a[200010],n,q;

void build(int i,int l,int r)
{
	t[i].l=l; t[i].r=r; t[i].val=0;
	if (l==r) {t[i].val=a[l]; return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}

void pushdown(int i)
{
	t[i<<1].val=max(t[i].val,t[i<<1].val);
	t[i<<1|1].val=max(t[i].val,t[i<<1|1].val);
	t[i].val=0;
}

void change(int i,int x,int v)
{
	if (t[i].l==t[i].r) {t[i].val=v; return;}
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (x<=mid) change(i<<1,x,v); else change(i<<1|1,x,v);
}

void dfs(int i)
{
	if (t[i].l==t[i].r) {printf("%d ",t[i].val); return;}
	pushdown(i),dfs(i<<1),dfs(i<<1|1);
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	build(1,1,n),scanf("%d",&q);
	while (q--)
	{
		int ord,x,y;
		scanf("%d",&ord);
		if (ord==1) scanf("%d%d",&x,&y),change(1,x,y);
		else scanf("%d",&x),t[1].val=max(t[1].val,x);
	}
	dfs(1);
	return 0;
}