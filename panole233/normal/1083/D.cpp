#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
struct node{int l,r,a[4],v[4],laz[4],mi,ma;}t[400010];
int n,a[100010],pl[100010],pr[100010],R;
map<int,int> ma;

void build(int i,int l,int r)
{
	for (int j=0; j<4; j++) t[i].laz[j]=-1;
	t[i].l=l,t[i].r=r;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}

void pushdown(int i)
{
	int i1=(i<<1),i2=(i<<1|1),v;
	if (t[i].laz[0]!=-1)
	{
		v=t[i].laz[0],t[i].laz[0]=-1;
		t[i1].v[0]=1ll*v*t[i1].a[2]%mod,t[i1].v[1]=1ll*v*t[i1].a[3]%mod;
		t[i1].a[0]=1ll*(t[i1].r-t[i1].l+1)*v%mod,t[i1].laz[0]=v;
		t[i2].v[0]=1ll*v*t[i2].a[2]%mod,t[i2].v[1]=1ll*v*t[i2].a[3]%mod;
		t[i2].a[0]=1ll*(t[i2].r-t[i2].l+1)*v%mod,t[i2].laz[0]=v;
		t[i1].ma=t[i2].ma=v;
	}
	if (t[i].laz[1]!=-1)
	{
		v=t[i].laz[1],t[i].laz[1]=-1;
		t[i1].v[2]=1ll*v*t[i1].a[2]%mod,t[i1].v[3]=1ll*v*t[i1].a[3]%mod;
		t[i1].a[1]=1ll*(t[i1].r-t[i1].l+1)*v%mod,t[i1].laz[1]=v;
		t[i2].v[2]=1ll*v*t[i2].a[2]%mod,t[i2].v[3]=1ll*v*t[i2].a[3]%mod;
		t[i2].a[1]=1ll*(t[i2].r-t[i2].l+1)*v%mod,t[i2].laz[1]=v;
	}
	if (t[i].laz[2]!=-1)
	{
		v=t[i].laz[2],t[i].laz[2]=-1;
		t[i1].v[0]=1ll*v*t[i1].a[0]%mod,t[i1].v[2]=1ll*v*t[i1].a[1]%mod;
		t[i1].a[2]=1ll*(t[i1].r-t[i1].l+1)*v%mod,t[i1].laz[2]=v;
		t[i2].v[0]=1ll*v*t[i2].a[0]%mod,t[i2].v[2]=1ll*v*t[i2].a[1]%mod;
		t[i2].a[2]=1ll*(t[i2].r-t[i2].l+1)*v%mod,t[i2].laz[2]=v;
	}
	if (t[i].laz[3]!=-1)
	{
		v=t[i].laz[3],t[i].laz[3]=-1;
		t[i1].v[1]=1ll*v*t[i1].a[0]%mod,t[i1].v[3]=1ll*v*t[i1].a[1]%mod;
		t[i1].a[3]=1ll*(t[i1].r-t[i1].l+1)*v%mod,t[i1].laz[3]=v;
		t[i2].v[1]=1ll*v*t[i2].a[0]%mod,t[i2].v[3]=1ll*v*t[i2].a[1]%mod;
		t[i2].a[3]=1ll*(t[i2].r-t[i2].l+1)*v%mod,t[i2].laz[3]=v;
		t[i1].mi=t[i2].mi=v;
	}
}

int add(int x,int y) {return (x+y>=mod?x+y-mod:x+y);}

bool check(int i,int x)
{
	if (t[i].l==t[i].r) return (t[i].a[0]>=t[i].a[1]&&t[i].a[2]>=t[i].a[3]);
	pushdown(i);
	int mid=(t[i].l+t[i].r)>>1;
	if (x<=mid) return check(i<<1,x);
	else return check(i<<1|1,x);
}

void change(int i,int l,int r,int v,int p)
{
	if (l>r) return;
	if (t[i].l==l&&t[i].r==r) 
	{
		if (p==0) t[i].v[0]=1ll*v*t[i].a[2]%mod,t[i].v[1]=1ll*v*t[i].a[3]%mod,t[i].ma=v; else
		if (p==1) t[i].v[2]=1ll*v*t[i].a[2]%mod,t[i].v[3]=1ll*v*t[i].a[3]%mod; else
		if (p==2) t[i].v[0]=1ll*v*t[i].a[0]%mod,t[i].v[2]=1ll*v*t[i].a[1]%mod; else
		if (p==3) t[i].v[1]=1ll*v*t[i].a[0]%mod,t[i].v[3]=1ll*v*t[i].a[1]%mod,t[i].mi=v;
		t[i].a[p]=1ll*(r-l+1)*v%mod,t[i].laz[p]=v; return;
	}
	pushdown(i);
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) change(i<<1,l,r,v,p); else
	if (l>mid) change(i<<1|1,l,r,v,p); else
	change(i<<1,l,mid,v,p),change(i<<1|1,mid+1,r,v,p);
	for (int j=0; j<4; j++) t[i].v[j]=(t[i<<1].v[j]+t[i<<1|1].v[j])%mod,t[i].a[j]=(t[i<<1].a[j]+t[i<<1|1].a[j])%mod;
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi),t[i].ma=max(t[i<<1].ma,t[i<<1|1].ma);
}

int query(int i,int l,int r)
{
	if (l>r) return 0;
	if (t[i].l==l&&t[i].r==r) return (10ll*mod+t[i].v[0]-t[i].v[1]-t[i].v[2]+t[i].v[3])%mod;
	pushdown(i);
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return query(i<<1,l,r);
	if (l>mid) return query(i<<1|1,l,r);
	return add(query(i<<1,l,mid),query(i<<1|1,mid+1,r));
}

int findl(int i,int x,int v)
{
	if (t[i].l==t[i].r) return t[i].l-(t[i].a[3]>v);
	pushdown(i);
	int mid=(t[i].l+t[i].r)>>1;
	if (x>mid) return findl(i<<1|1,x,v);
	if (t[i<<1|1].mi<=v) return findl(i<<1|1,x,v);
	else return findl(i<<1,x,v);
}

int findr(int i,int x,int v)
{
	if (t[i].l==t[i].r) return t[i].l-(t[i].a[0]<v);
	pushdown(i);
	int mid=(t[i].l+t[i].r)>>1;
	if (x>mid) return findr(i<<1|1,x,v);
	if (t[i<<1|1].ma>=v) return findr(i<<1|1,x,v);
	else return findr(i<<1,x,v);
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	build(1,1,n),R=n,ma.clear();
	for (int i=1; i<=n; i++) pl[i]=ma[a[i]],ma[a[i]]=i;
	ma.clear();
	for (int i=n; i; i--) pr[i]=ma[a[i]],ma[a[i]]=i;
	for (int i=1; i<=n; i++) if (!pr[i]) pr[i]=n+1;
	for (int i=1; i<=n; i++) pl[i]++,pr[i]--;
	int ans=0;
	for (int i=n; i; i--)
	{
		change(1,i,i,i,1),change(1,i,n,i,2),change(1,i,i,pr[i],0),change(1,i,i,pl[i],3);
		change(1,i,findr(1,i,pr[i]),pr[i],0),change(1,i,findl(1,i,pl[i]),pl[i],3);
		while (R>=i&&!check(1,R)) R--;
		ans=add(ans,query(1,i,R));
	}
	printf("%d\n",ans);
	return 0;
}