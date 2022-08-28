#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,q[200005][3],val=2e5+1;
ll sum[9000005],lazy[9000005];
int ls[9000005],rs[9000005],ct,rt[200005],rct,a[200005],st[200005],tp;
char s[105];
void pushup(int x)
{
	sum[x]=min(sum[ls[x]],sum[rs[x]]);
}
void col(int x,ll v)
{
	sum[x]+=v;
	lazy[x]+=v;
}
void pushdown(int x)
{
	if(lazy[x])
	{
		if(ls[x]) col(ls[x],lazy[x]);
		if(rs[x]) col(rs[x],lazy[x]);
		lazy[x]=0;
	}
}
void modify(int x,int l,int r,int ql,int qr,ll v)
{
	if(l>qr||r<ql||!x) return;
	if(ql<=l&&r<=qr)
	{
		col(x,v);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	modify(ls[x],l,mid,ql,qr,v);
	modify(rs[x],mid+1,r,ql,qr,v);
	pushup(x);
}
int modify2(int x,int l,int r,int qx,ll v)
{
	if(l>qx||r<qx) return x;
	if(!x) x=++ct;
	if(l==r)
	{
		sum[x]=v;
		return x;
	}
	pushdown(x);
	int mid=(l+r)/2;
	ls[x]=modify2(ls[x],l,mid,qx,v);
	rs[x]=modify2(rs[x],mid+1,r,qx,v);
	pushup(x);
	return x;
}
ll query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql||!x) return 1e18;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;
	pushdown(x);
	return min(query(ls[x],l,mid,ql,qr),query(rs[x],mid+1,r,ql,qr));
}
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	sum[x]=min(sum[x],sum[y]);
	pushdown(x),pushdown(y);
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	return x;
}
void print(int x,int l,int r)
{
	if(!x) return;
	printf("x=%d,l=%d,r=%d,sum=%lld,lazy=%lld\n",x,l,r,sum[x],lazy[x]);
	if(l==r) return;
	int mid=(l+r)/2;
	pushdown(x);
	print(ls[x],l,mid);
	print(rs[x],mid+1,r);
}
int solve(int x,ll c,int l,int r)
{
	rct++;
	int u=rct;
	rt[u]=modify2(rt[u],1,val,x,c);
	for(int i=l;i<=r;i++)
	{
		if(q[i][0]==0)
		{
			int y=q[i][1],v=q[i][2];
			ll mn=sum[rt[u]];
		//	if(q==1e18) q=0;
			modify(rt[u],1,val,1,val,v);
			if(y!=m) rt[u]=modify2(rt[u],1,val,y,mn);
		}
		if(q[i][0]==1)
		{
			int v=solve(q[i][1],query(rt[u],1,val,q[i][1],q[i][1]),i+1,a[i]-1);
			rt[u]=modify2(rt[u],1,val,q[i][1],1e18);
			rt[u]=merge(rt[u],rt[v]);
			i=a[i];
		}
	}
//	printf("solve:x=%d,c=%lld,l=%d,r=%d\n",x,c,l,r);
//	print(rt[u],1,val);
	return u;
}
int main()
{
	sum[0]=1e18;
	scanf("%d%d",&n,&m);
	m++;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		if(s[0]=='s')
		{
			q[i][0]=0;
			scanf("%d%d",&q[i][1],&q[i][2]);
			q[i][1]++;
		}
		else if(s[0]=='i')
		{
			q[i][0]=1;
			scanf("%d",&q[i][1]);
			q[i][1]++;
		}
		else q[i][0]=2;
	}
	for(int i=1;i<=n;i++)
	{
		if(q[i][0]==1) st[++tp]=i;
		if(q[i][0]==2)
		{
			a[st[tp]]=i;
			tp--;
		}
	}
	int q=solve(1,0,1,n);
	printf("%lld\n",sum[q]);
	return 0;
}