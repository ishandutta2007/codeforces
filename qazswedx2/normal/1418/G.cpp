#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[500005],vis[500005],pre[500005][3];
int sum[2000005],lazy[2000005],ct[2000005];
void pushup(int x)
{
	sum[x]=min(sum[x*2],sum[x*2+1]);
	ct[x]=0;
	if(sum[x*2]==sum[x])  ct[x]+=ct[x*2];
	if(sum[x*2+1]==sum[x]) ct[x]+=ct[x*2+1];
}
void col(int x,int v)
{
	sum[x]+=v;
	lazy[x]+=v;
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
		ct[x]=1;
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
	int mid=(l+r)/2;
	pushdown(x);
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum[x]==0?ct[x]:0;
	int mid=(l+r)/2;
	pushdown(x);
	return query(x*2,l,mid,ql,qr)+query(x*2+1,mid+1,r,ql,qr); 
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		pre[i][0]=vis[a[i]];
		vis[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		pre[i][1]=pre[pre[i][0]][0];
		pre[i][2]=pre[pre[i][1]][0];
	}
	build(1,1,n);
	int l=1;
	ll ans=0; 
	for(int i=1;i<=n;i++)
	{
		l=max(l,pre[i][2]+1);
		modify(1,1,n,pre[i][2]+1,pre[i][0],-1);
		modify(1,1,n,pre[i][0]+1,i,2);
		ans+=query(1,1,n,l,i);
	//	printf("i=%d,pre=%d,%d,%d,l=%d,q=%d\n",i,pre[i][0],pre[i][1],pre[i][2],l,query(1,1,n,l,i));
	}
	printf("%lld",ans);
	return 0;
}