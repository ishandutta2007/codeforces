#include<bits/stdc++.h>
using namespace std;

struct node
{
	int l,r,po,lazp;
	long long mi,ma,dis,laz,lazd;
	bool bo;
}t[400010];

long long mi[10];
int a[100010],q,n,ord,x,l,r;

void pushdown(int i)
{
	if (!t[i].laz&&!t[i].bo) return;
	if (t[i].bo)
	{
		t[i<<1].mi=t[i<<1].ma=t[i<<1].laz=t[i].laz;
		t[i<<1|1].mi=t[i<<1|1].ma=t[i<<1|1].laz=t[i].laz;
		t[i<<1].lazd=t[i<<1|1].lazd=t[i<<1].dis=t[i<<1|1].dis=t[i].lazd;
		t[i<<1].lazp=t[i<<1|1].lazp=t[i<<1].po=t[i<<1|1].po=t[i].lazp;
		t[i<<1].bo=t[i<<1|1].bo=1,t[i].bo=0;
	} else
	{
		t[i<<1].laz+=t[i].laz,t[i<<1|1].laz+=t[i].laz;
		t[i<<1].mi+=t[i].laz,t[i<<1|1].mi+=t[i].laz;
		t[i<<1].ma+=t[i].laz,t[i<<1|1].ma+=t[i].laz;
		t[i<<1].dis-=t[i].laz,t[i<<1|1].dis-=t[i].laz;
		t[i<<1].lazd-=t[i].laz,t[i<<1|1].lazd-=t[i].laz;
	}
	t[i].laz=t[i].lazd=0,t[i].lazp=0;
}

void upd(int i)
{
	t[i].dis=min(t[i<<1].dis,t[i<<1|1].dis);
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
	t[i].ma=max(t[i<<1].ma,t[i<<1|1].ma);
	t[i].po=t[i<<1].po;
}

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].laz=t[i].lazd=0,t[i].bo=0,t[i].lazp=0;
	if (l==r) 
	{
		t[i].mi=t[i].ma=a[l];
		for (int j=0; j<10; j++) if (mi[j]>t[i].mi) {t[i].dis=mi[j]-t[i].mi,t[i].po=j; break;}
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r),upd(i);
}

void change(int i,int l,int r,long long val,long long d,int po)
{
	if (t[i].l==l&&t[i].r==r) 
	{
		t[i].dis=t[i].lazd=d,t[i].po=t[i].lazp=po;
		t[i].mi=t[i].ma=t[i].laz=val;
		t[i].bo=1; return;
	}
	int mid=(t[i].l+t[i].r)>>1; pushdown(i);
	if (r<=mid) change(i<<1,l,r,val,d,po); else
	if (l>mid) change(i<<1|1,l,r,val,d,po); else
	change(i<<1,l,mid,val,d,po),change(i<<1|1,mid+1,r,val,d,po);
	upd(i);
}

void add(int i,int l,int r,long long val)
{
	if (t[i].l==l&&t[i].r==r)
	{
		t[i].mi+=val,t[i].ma+=val,t[i].laz+=val;
		t[i].dis-=val,t[i].lazd-=val; return;
	}
	int mid=(t[i].l+t[i].r)>>1; pushdown(i);
	if (r<=mid) add(i<<1,l,r,val); else
	if (l>mid) add(i<<1|1,l,r,val); else
	add(i<<1,l,mid,val),add(i<<1|1,mid+1,r,val);
	upd(i);
}

void renew(int i)
{
	if (t[i].mi==t[i].ma)
	{
		while (t[i].dis<0) t[i].dis+=mi[t[i].po+1]-mi[t[i].po],t[i].po++;
		t[i].laz=t[i].mi,t[i].lazd=t[i].dis,t[i].lazp=t[i].po,t[i].bo=1;
		return;
	}
	pushdown(i);
	if (t[i<<1].dis<0) renew(i<<1);
	if (t[i<<1|1].dis<0) renew(i<<1|1);
	upd(i);
}

long long query(int i,int x)
{
	if (t[i].l==t[i].r) return t[i].mi;
	int mid=(t[i].l+t[i].r)>>1; pushdown(i);
	return query(i<<1|(x>mid),x);
}

int main()
{
	mi[0]=1;
	for (int i=1; i<10; i++) mi[i]=42ll*mi[i-1];
	scanf("%d%d",&n,&q);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	build(1,1,n);
	while (q--)
	{
		scanf("%d",&ord);
		if (ord==1) scanf("%d",&x),printf("%I64d\n",query(1,x)); else
		if (ord==2) 
		{
			scanf("%d%d%d",&l,&r,&x);
			int p; long long dis;
			for (int i=1; i<10; i++) if (mi[i]>x) {dis=mi[i]-x,p=i; break;}
			change(1,l,r,x,dis,p);
		} else
		{
			scanf("%d%d%d",&l,&r,&x);
			add(1,l,r,x),renew(1);
			while (t[1].dis==0) add(1,l,r,x),renew(1);
		}
	}
	return 0;
}