#include<bits/stdc++.h>
using namespace std;

int n,T,l[200010],r[200010],q;
char s1[200010],s2[200010];

struct node
{
	int l,r,laz,val;
}t[800010];

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].laz=-1;
	if (l==r) {t[i].val=s2[l]-'0'; return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
	t[i].val=t[i<<1].val+t[i<<1|1].val;
}

void pushdown(int i)
{
	if (t[i].laz==-1) return;
	t[i<<1].laz=t[i].laz,t[i<<1].val=(t[i<<1].r-t[i<<1].l+1)*t[i].laz;
	t[i<<1|1].laz=t[i].laz,t[i<<1|1].val=(t[i<<1|1].r-t[i<<1|1].l+1)*t[i].laz;
	t[i].laz=-1;
}

void change(int i,int l,int r,int v)
{
	if (t[i].l==l&&t[i].r==r) {t[i].val=v*(r-l+1),t[i].laz=v; return;}
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) change(i<<1,l,r,v); else
	if (l>mid) change(i<<1|1,l,r,v); else
	change(i<<1,l,mid,v),change(i<<1|1,mid+1,r,v);
	t[i].val=t[i<<1].val+t[i<<1|1].val;
}

int query(int i,int l,int r)
{
	if (t[i].l==l&&t[i].r==r) return t[i].val;
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return query(i<<1,l,r);
	if (l>mid) return query(i<<1|1,l,r);
	return query(i<<1,l,mid)+query(i<<1|1,mid+1,r);
}

bool chk(int i)
{
	if (t[i].l==t[i].r) return t[i].val==(s1[t[i].l]-'0');
	pushdown(i); return chk(i<<1)&chk(i<<1|1);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s",s1+1),scanf("%s",s2+1);
		build(1,1,n);
		for (int i=1; i<=q; i++) scanf("%d%d",&l[i],&r[i]);
		bool bo=1;
		for (int i=q; i; i--)
		{
			int v=query(1,l[i],r[i]);
			if (v*2==(r[i]-l[i]+1)) {bo=0; break;}
			if (v*2<r[i]-l[i]+1) change(1,l[i],r[i],0);
			else change(1,l[i],r[i],1);
		}
		bo&=chk(1);
		puts(bo?"YES":"NO");
	}
	return 0;
}