#include<bits/stdc++.h>
using namespace std;

struct node
{
	int l,r;
	long long mi,laz;
}t[400010];

const long long inf=4000000000000000000ll;
int n,a[100010],p,cnt,q[100010],l,r;
long long tim,ans[100010];

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].laz=0;
	if (l==r) {t[i].mi=a[l]; return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
}

void pushdown(int i)
{
	if (!t[i].laz) return;
	t[i<<1].mi+=t[i].laz,t[i<<1|1].mi+=t[i].laz;
	t[i<<1].laz+=t[i].laz,t[i<<1|1].laz+=t[i].laz;
	t[i].laz=0;
}

void add(int i,int l,int r,long long v)
{
	if (t[i].l==l&&t[i].r==r) {t[i].mi+=v,t[i].laz+=v; return;}
	int mid=(t[i].l+t[i].r)>>1; pushdown(i);
	if (r<=mid) add(i<<1,l,r,v); else
	if (l>mid) add(i<<1|1,l,r,v); else
	add(i<<1,l,mid,v),add(i<<1|1,mid+1,r,v);
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
}

long long Query(int i,int l,int r)
{
	if (t[i].l==l&&t[i].r==r) return t[i].mi;
	int mid=(t[i].l+t[i].r)>>1; pushdown(i);
	if (r<=mid) return Query(i<<1,l,r);
	if (l>mid) return Query(i<<1|1,l,r);
	return min(Query(i<<1,l,mid),Query(i<<1|1,mid+1,r));
}

int Find(int i)
{
	if (t[i].l==t[i].r) return t[i].l; pushdown(i);
	if (t[i<<1].mi<=0) return Find(i<<1); else return Find(i<<1|1);
}

int findmi(int i,int r,long long v)
{
	if (t[i].l==t[i].r) return t[i].l;
	int mid=(t[i].l+t[i].r)>>1; pushdown(i);
	if (r<=mid) return findmi(i<<1,r,v);
	if (t[i<<1].mi<=v) return findmi(i<<1,r,v);
	else return findmi(i<<1|1,r,v);
}

int main()
{
	tim=0,scanf("%d%d",&n,&p);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	build(1,1,n),cnt=0;
	long long NW=0;
	while (cnt<n)
	{
		if (t[1].mi>0) tim+=t[1].mi,add(1,1,n,-t[1].mi);
		q[l=r=1]=Find(1);
		while (l<=r)
		{
			ans[q[l]]=tim+p,add(1,q[l],q[l],inf),add(1,1,n,-p),tim+=p,cnt++;
			if (q[r]>1&&(NW=Query(1,1,q[r]-1))<=0) q[r+1]=findmi(1,q[r]-1,NW),r++;
			l++;
		}
	}
	for (int i=1; i<=n; i++) printf("%I64d ",ans[i]); puts("");
	return 0;
}