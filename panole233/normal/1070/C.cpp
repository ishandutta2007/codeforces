#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const long long inf=1000000000000000000ll;

int n,k,m,po;
long long ans[1000002],tr[1000002],mi,an;

struct node2
{
	int l,r,po;
	long long val,laz;
}t[4000001];

struct node
{
	int l,r,c,p;
}q[200001];

bool cmp(node a,node b) {return a.p<b.p;}

long long query(int x) {long long ans=0; for (; x; x-=(x&-x)) ans+=tr[x]; return ans;}
void add(int x,long long val) {for (; x<=n; x+=(x&-x)) tr[x]+=val;}

void build(int i,int l,int r)
{
	t[i].l=l; t[i].r=r; t[i].val=k; t[i].po=l; t[i].laz=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid); build(i<<1|1,mid+1,r);
}

void pushdown(int i)
{
	if (t[i].l==t[i].r||t[i].laz==0) return;
	t[i<<1].val-=t[i].laz; t[i<<1].laz+=t[i].laz;
	t[i<<1|1].val-=t[i].laz; t[i<<1|1].laz+=t[i].laz;
	t[i].laz=0;
}

void dec(int i,int l,int r,long long val)
{
	pushdown(i);
	if (l==t[i].l&&r==t[i].r) {t[i].val-=val; t[i].laz+=val; return;}
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) dec(i<<1,l,r,val); else
	if (l>mid) dec(i<<1|1,l,r,val); else
	dec(i<<1,l,mid,val),dec(i<<1|1,mid+1,r,val);
	if (t[i<<1].val<=t[i<<1|1].val) t[i].val=t[i<<1].val,t[i].po=t[i<<1].po;
	else t[i].val=t[i<<1|1].val,t[i].po=t[i<<1|1].po;
}

void find(int i,int l,int r)
{
	pushdown(i);
	if (l==t[i].l&&r==t[i].r) {if (t[i].val<mi) mi=t[i].val,po=t[i].po; return;}
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) find(i<<1,l,r); else
	if (l>mid) find(i<<1|1,l,r); else
	find(i<<1,l,mid),find(i<<1|1,mid+1,r);
}

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for (int i=1; i<=m; i++) scanf("%d%d%d%d",&q[i].l,&q[i].r,&q[i].c,&q[i].p);
	for (int i=1; i<=n; i++) ans[i]=-1;
	memset(tr,0,sizeof(tr));
	sort(q+1,q+1+m,cmp);
	build(1,1,n);
	for (int i=1; i<=m; i++)
	{
		po=0; mi=inf; find(1,q[i].l,q[i].r);
		while (mi<=q[i].c)
		{
			ans[po]=query(po)+mi*q[i].p;
			dec(1,po,po,-inf); po=0; mi=inf; find(1,q[i].l,q[i].r);
		}
		add(q[i].l,1ll*q[i].c*q[i].p); add(q[i].r+1,-1ll*q[i].c*q[i].p);
		dec(1,q[i].l,q[i].r,q[i].c);
	}
	an=0;
	for (int i=1; i<=n; i++)
	{
		if (ans[i]==-1) ans[i]=query(i);
		an+=ans[i];
	}
	printf("%I64d\n",an);
	return 0;
}