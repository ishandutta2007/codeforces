#include<bits/stdc++.h>
using namespace std;

struct node
{
	int l,r;
	bool bo;
	long long val;
}t[400001];

int a[100001],n,m,seed,vmax;

int rnd()
{
	int ret=seed;
	seed=(seed*7ll+13)%1000000007;
	return ret;
}

long long getmin(long long a,long long b) {return a<b?a:b;}

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r;
	if (l==r) {t[i].val=a[l],t[i].bo=1; return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
	t[i].bo=(t[i<<1].bo&t[i<<1|1].bo&(t[i<<1].val==t[i<<1|1].val));
	t[i].val=getmin(t[i<<1|1].val,t[i<<1].val);
}

void pushdown(int i)
{
	if (!t[i].bo) return;
	t[i<<1].bo=t[i<<1|1].bo=1;
	t[i<<1].val=t[i<<1|1].val=t[i].val;
}

void change(int i,int l,int r,int v)
{
	if (t[i].l==l&&t[i].r==r) {t[i].val=v,t[i].bo=1; return;}
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) change(i<<1,l,r,v); else
	if (l>mid) change(i<<1|1,l,r,v); else
	change(i<<1,l,mid,v),change(i<<1|1,mid+1,r,v);
	t[i].bo=(t[i<<1].bo&t[i<<1|1].bo&(t[i<<1].val==t[i<<1|1].val));
	t[i].val=getmin(t[i<<1].val,t[i<<1|1].val);
}

void add(int i,int l,int r,long long v)
{
	if (t[i].l==l&&t[i].r==r&&t[i].bo) {t[i].val+=v; return;}
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) add(i<<1,l,r,v); else
	if (l>mid) add(i<<1|1,l,r,v); else
	add(i<<1,l,mid,v),add(i<<1|1,mid+1,r,v);
	t[i].bo=(t[i<<1].bo&t[i<<1|1].bo&(t[i<<1].val==t[i<<1|1].val));
	t[i].val=getmin(t[i<<1].val,t[i<<1|1].val);
}

int query_min(int i,int l,int r,long long v)
{
	if (t[i].val>=v) return 0;
	if (t[i].bo) return r-l+1;
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return query_min(i<<1,l,r,v);
	if (l>mid) return query_min(i<<1|1,l,r,v);
	return query_min(i<<1,l,mid,v)+query_min(i<<1|1,mid+1,r,v);
}

int quickmi(int a,int b,int mod)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

int Add(int x,int y,int mod) {return (x+y>=mod?x+y-mod:x+y);}

int query_mi(int i,int l,int r,int k,int mod)
{
	if (t[i].bo) return 1ll*(r-l+1)*quickmi(t[i].val%mod,k,mod)%mod;
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return query_mi(i<<1,l,r,k,mod); 
	if (l>mid) return query_mi(i<<1|1,l,r,k,mod);
	return Add(query_mi(i<<1,l,mid,k,mod),query_mi(i<<1|1,mid+1,r,k,mod),mod);
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for (int i=1; i<=n; i++) a[i]=rnd()%vmax+1;
	build(1,1,n);
	while (m--)
	{
		int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x,y;
		if (l>r) swap(l,r);
		if (op==3) x=rnd()%(r-l+1)+1; else x=rnd()%vmax+1;
		if (op==4) y=rnd()%vmax+1;
		if (op==1) add(1,l,r,x); else
		if (op==2) change(1,l,r,x); else
		if (op==4) printf("%d\n",query_mi(1,l,r,x,y)); else
		{
			long long L=0,R=100001ll*vmax,Mid,Ans;
			while (L<=R)
			{
				Mid=(L+R)>>1;
				if (query_min(1,l,r,Mid)<x) Ans=Mid,L=Mid+1;
				else R=Mid-1;
			}
			printf("%I64d\n",Ans);
		}
	}
	return 0;
}