#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int l,r,id;
	bool operator<(const pt x) const
	{
		return r>x.r;
	}
}p[1000005];
int n,a[100005],lazy[1000005],sum[1000005],b[100005],vis[100005];
int nxt[100005],t,qans[100005];
void pushup(int x)
{
	sum[x]=min(sum[x*2],sum[x*2+1]);
}
void col(int x,int v)
{
	lazy[x]=v;
	sum[x]=v;
}
void pushdown(int x)
{
	if(lazy[x])
	{
		col(x*2,lazy[x]);
		col(x*2+1,lazy[x]);
		lazy[x]=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=b[l];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,v);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
int queryk(int x,int l,int r,int v)
{
	if(l==r)
	{
		if(sum[x]<=v) return l;
		return 0;
	}
	pushdown(x);
	int mid=(l+r)/2;
	if(sum[x*2]<=v) return queryk(x*2,l,mid,v);
	return queryk(x*2+1,mid+1,r,v);
}
int query(int x,int l,int r,int qx)
{
	if(l>qx||r<qx) return 0;
	if(l==r) return sum[x];
	pushdown(x);
	int mid=(l+r)/2;
	return query(x*2,l,mid,qx)+query(x*2+1,mid+1,r,qx);
}
void print(int x,int l,int r)
{
	if(l==r)
	{
		printf("%d ",sum[x]);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	print(x*2,l,mid);
	print(x*2+1,mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	b[n+1]=1;
	for(int i=n;i>0;i--)
	{
		vis[a[i]]++;
		b[i]=b[i+1];
		while(vis[b[i]]) b[i]++;
	}
	build(1,1,n);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		nxt[i]=vis[a[i]];
		vis[a[i]]=i;
		++t;
		p[t].r=i-1;
		p[t].l=nxt[i]+1;
		p[t].id=a[i];
	}
	for(int i=1;i<=n+1;i++)
	{
		++t;
		p[t].l=vis[i]+1,p[t].r=n,p[t].id=i;
	}
	sort(p+1,p+t+1);
	int nw=1;
	for(int i=n;i>0;i--)
	{
	//	print(1,1,n);
	//	printf("\n");
		while(nw<=t&&p[nw].r==i)
		{
			if(p[nw].l>p[nw].r)
			{
				nw++;
				continue;
			}
			int q=query(1,1,n,p[nw].l);
		//	if(p[nw].id<=6)printf("i=%d,p=%d,%d,%d,q=%d\n",i,p[nw].l,p[nw].r,p[nw].id,q);
			if(q==p[nw].id) qans[q]=1;
			nw++;
		}
		int r=queryk(1,1,n,a[i]);
		if(!r) r=n;
		else r--;
		modify(1,1,n,nxt[i]+1,r,a[i]);
	}
	int ans=1;
	while(qans[ans]) ans++;
	printf("%d\n",ans);
	return 0;
}