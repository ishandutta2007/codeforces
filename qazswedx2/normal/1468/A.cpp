#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int t,n,a[500005],sum[2000005];
priority_queue<int,vector<int>,greater<int> > pq;
void pushup(int x)
{
	sum[x]=max(sum[x*2],sum[x*2+1]);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=-1e9;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]=max(sum[x],v);
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return -1e9;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;
	return max(query(x*2,l,mid,ql,qr),query(x*2+1,mid+1,r,ql,qr));
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		while(!pq.empty()) pq.pop();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]++;
		}
		a[0]=1;
		build(1,1,n+1);
		for(int i=0;i<=n;i++)
		{
			int q=query(1,1,n+1,1,a[i]);
			q=max(q,0)+1;
			while(!pq.empty())
			{
				int u=pq.top();
				if(u>a[i]) break;
				pq.pop();
				modify(1,1,n+1,u,query(1,1,n+1,u,u)+1);
			}
			modify(1,1,n+1,a[i],q);
			pq.push(a[i]);
		//	printf("i=%d,a=%d,q=%d\n",i,a[i],q);
		}
		printf("%d\n",sum[1]-1);
	}
	return 0;
}