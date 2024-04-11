#include<bits/stdc++.h>
using namespace std;

const int inf=1000000000;

struct node
{
	int lazz,lazf,pmi,pma,mi,l,r;
}t[800010];

int n,q,s,d,a[200010],x,y,ans[200010];

void upd_z(int i,int laz)
{
	t[i].mi=min(t[i].mi,t[i].pmi+laz);
	t[i].lazz=min(t[i].lazz,laz);
}

void upd_f(int i,int laz)
{
	t[i].mi=min(t[i].mi,-t[i].pma+laz);
	t[i].lazf=min(t[i].lazf,laz);
}

void upd(int i)
{
	t[i].pmi=min(t[i<<1].pmi,t[i<<1|1].pmi);
	t[i].pma=max(t[i<<1].pma,t[i<<1|1].pma);
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
}

void pushdown(int i)
{
	if (t[i].lazz!=inf)
	{
		upd_z(i<<1,t[i].lazz);
		upd_z(i<<1|1,t[i].lazz);
		t[i].lazz=inf;
	}
	if (t[i].lazf!=inf)
	{
		upd_f(i<<1,t[i].lazf);
		upd_f(i<<1|1,t[i].lazf);
		t[i].lazf=inf;
	}
}

void add(int i,int l,int r,int k,int v)
{
	if (t[i].l==l&&t[i].r==r)
	{
		if (k==1) upd_z(i,v); else upd_f(i,v);
		return;
	}
	pushdown(i);
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) add(i<<1,l,r,k,v); else
	if (l>mid) add(i<<1|1,l,r,k,v); else
	add(i<<1,l,mid,k,v),add(i<<1|1,mid+1,r,k,v);
	upd(i);
}

void build(int i,int l,int r)
{
	t[i].lazz=t[i].lazf=t[i].mi=inf,t[i].l=l,t[i].r=r;
	if (l==r) {t[i].pmi=t[i].pma=a[l]; return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
	upd(i);
}

void del(int i,int x)
{
	if (t[i].l==t[i].r) {t[i].pmi=inf,t[i].pma=-inf,t[i].mi=inf; return;}
	pushdown(i);
	int mid=(t[i].l+t[i].r)>>1;
	del(i<<1|(x>mid),x);
	upd(i);
}

int findmi(int i)
{
	if (t[i].l==t[i].r) return t[i].l;
	pushdown(i);
	int mid=(t[i].l+t[i].r)>>1;
	return findmi(i<<1|(t[i<<1].mi>t[i<<1|1].mi));
}

void work(int s)
{
	del(1,s);
	int p=lower_bound(a+1,a+1+n,a[s]-d)-a;
	if (p<=n) add(1,p,n,1,-a[s]+d);
	if (p>1) add(1,1,p-1,-1,a[s]-d);
	p=lower_bound(a+1,a+1+n,a[s]+d)-a;
	if (p<=n) add(1,p,n,1,-a[s]-d);
	if (p>1) add(1,1,p-1,-1,a[s]+d);
}

int main()
{
	scanf("%d%d%d%d",&n,&q,&s,&d);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	build(1,1,n),work(s),ans[s]=0;
	int la=0;
	for (int i=1; i<n; i++)
	{
		int p=findmi(1);
		la=ans[p]=max(la,t[1].mi);
		work(p);
	}
	while (q--)
	{
		scanf("%d%d",&x,&y);
		puts(ans[x]<=y?"Yes":"No");
	}
	return 0;
}