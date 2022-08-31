#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct pt
{
	int val,id;
	pt(int val=0,int id=0):val(val),id(id){}
	bool operator<(const pt x) const
	{
		return val>x.val;
	}
};
struct qt
{
	int l,r,id;
	bool operator<(const qt x) const
	{
		return l<x.l;
	}
}q[1000005];
priority_queue<pt> pq;
int n,a[500005],b[500005],p[500005],c[500005],sum[1000005],sumid[1000005];
void pushup(int x)
{
	sum[x]=min(sum[x*2],sum[x*2+1]);
	if(sum[x]==sum[x*2]) sumid[x]=sumid[x*2];
	else sumid[x]=sumid[x*2+1];
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sumid[x]=l;
		sum[x]=a[c[l]];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void query(int x,int l,int r,int ql,int qr,int &ans,int &id)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		if(ans>sum[x])
		{
			ans=sum[x];
			id=sumid[x];
		}
		return;
	}
	int mid=(l+r)/2;
	query(x*2,l,mid,ql,qr,ans,id);
	query(x*2+1,mid+1,r,ql,qr,ans,id);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		q[i].l=a[i],q[i].r=b[i],q[i].id=i;
	}
	sort(q+1,q+n+1);
	int nw=1;
	for(int i=1;i<=n;i++)
	{
		while(nw<=n&&q[nw].l==i)
			pq.push(pt(q[nw].r,q[nw].id)),nw++;
		int u=pq.top().id;
		pq.pop();
		p[u]=i;
	}
	/*for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
	printf("\n");*/
	for(int i=1;i<=n;i++)
		c[p[i]]=i;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int ans=1e9,id=0;
		//query(1,1,n,a[c[i]],i-1,ans,id);
		query(1,1,n,i+1,b[c[i]],ans,id);
		if(ans<=i)
		{
			//printf("i=%d,ans=%d,id=%d,c=%d,%d\n",i,ans,id,c[i],c[id]);
			printf("NO\n");
			for(int i=1;i<=n;i++)
				printf("%d ",p[i]);
			printf("\n");
			swap(p[c[i]],p[c[id]]);
			for(int i=1;i<=n;i++)
				printf("%d ",p[i]);
			printf("\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
	printf("\n");
	return 0;
}