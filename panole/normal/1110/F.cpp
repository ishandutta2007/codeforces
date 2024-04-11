#include<bits/stdc++.h>
using namespace std;

const long long inf=1000000000000000000ll;
int n,x,y,w,m,ql,qr,hd[500010],cnt,L[500010],R[500010],o[21],oN;
long long ans[500001];
vector<pair<pair<int,int>,int> > q[500001];

struct node
{
	long long val;
	int to,next;
}e[500001];

struct node2
{
	long long val,laz;
	int l,r;
}t[2000001];

void addedge(int x,int y,long long val)
{
	e[++cnt].next=hd[x];
	hd[x]=cnt;
	e[cnt].to=y;
	e[cnt].val=val;
}

void build(int i,int l,int r)
{
	t[i].l=l; t[i].r=r; t[i].val=inf; t[i].laz=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid); build(i<<1|1,mid+1,r);
}

void pushdown(int i)
{
	if (t[i].laz==0) return;
	int i1=(i<<1),i2=(i1|1);
	long long la=t[i].laz;
	t[i].laz=0;
	t[i1].laz+=la,t[i1].val+=la;
	t[i2].laz+=la,t[i2].val+=la;
}

long long getmin(long long a,long long b) {return a<b?a:b;}

void add(int i,int l,int r,long long v)
{
	if (l>r) return;
	if (t[i].l==l&&t[i].r==r) {t[i].val+=v; t[i].laz+=v; return;}
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) add(i<<1,l,r,v); else
	if (l>mid) add(i<<1|1,l,r,v); else
	add(i<<1,l,mid,v),add(i<<1|1,mid+1,r,v);
	t[i].val=getmin(t[i<<1].val,t[i<<1|1].val);
}

long long query(int i,int l,int r)
{
	if (t[i].l==l&&t[i].r==r) return t[i].val;
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return query(i<<1,l,r);
	if (l>mid) return query(i<<1|1,l,r);
	return getmin(query(i<<1,l,mid),query(i<<1|1,mid+1,r));
}

void dfs(int x,long long dep)
{
	L[x]=R[x]=x;
	if (!hd[x]) {add(1,x,x,dep-inf); return;}
	for (int i=hd[x]; i; i=e[i].next) dfs(e[i].to,dep+e[i].val),R[x]=max(R[x],R[e[i].to]);
}

void work(int x,long long dep)
{
	for (int i=0,sz=q[x].size(); i<sz; i++) ans[q[x][i].second]=query(1,q[x][i].first.first,q[x][i].first.second)+dep;
	for (int i=hd[x]; i; i=e[i].next)
	{
		add(1,L[e[i].to],R[e[i].to],-2*e[i].val);
		work(e[i].to,dep+e[i].val);
		add(1,L[e[i].to],R[e[i].to],2*e[i].val);
	}
}

void pri(long long x)
{
	if (x==0) putchar('0'); else
	{
		oN=0;
		while (x) o[++oN]=x%10,x/=10;
		for (int i=oN; i; i--) putchar(o[i]+48);
	}
	putchar('\n');
}

int main()
{
	scanf("%d%d",&n,&m); cnt=0; memset(hd,0,sizeof(hd));
	for (int i=2; i<=n; i++) scanf("%d%d",&x,&w),addedge(x,i,w);
	build(1,1,n); dfs(1,0);
	for (int i=1; i<=m; i++) 
	{
		scanf("%d%d%d",&x,&ql,&qr);
	    q[x].push_back(make_pair(make_pair(ql,qr),i));
	}
	work(1,0);
	for (int i=1; i<=m; i++) pri(ans[i]);
	return 0;
}