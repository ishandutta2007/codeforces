#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
namespace SGT
{
	int sum[2000005],sumid[2000005],lazy[2000005];
	void pushup(int x)
	{
		sum[x]=min(sum[x*2],sum[x*2+1]);
		if(sum[x]==sum[x*2]) sumid[x]=sumid[x*2];
		else sumid[x]=sumid[x*2+1];
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
		lazy[x]=0;
		if(l==r)
		{
			sum[x]=0;
			sumid[x]=l;
			return;
		}
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
		pushup(x);
	}
	void modify(int x,int l,int r,int ql,int qr,int v)
	{
	//	if(x==1) printf("modify:ql=%d,qr=%d,v=%d\n",ql,qr,v);
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
	int query(int x,int l,int r,int qx)
	{
		if(l>qx||r<qx) return 0;
		if(l==r) return sum[x];
		pushdown(x);
		int mid=(l+r)/2;
		return query(x*2,l,mid,qx)+query(x*2+1,mid+1,r,qx);
	}
}
int n,m,len,p[1000005],rp[1000005];
ll suml,sumr;
inline int getdis(int x,int y)
{
	if(y>=x) return y-x;
	return len-x+y;
}
void upd2(int x,int fl)
{
	if(x==1||x==len+1||!rp[x-1]||!rp[x]) return;
//	printf("upd2:x=%d,fl=%d,rp=%d,%d\n",x,fl,rp[x-1],rp[x]);
	if(x<=n) suml+=fl*getdis(rp[x-1],rp[x]);
	else sumr+=fl*getdis(rp[x-1],rp[x]);
}
void updrp(int x,int y)
{
	upd2(x,-1);
	upd2(x+1,-1);
	rp[x]=y;
	upd2(x,1);
	upd2(x+1,1);
}
void updp(int x,int y)
{
	SGT::modify(1,1,len,x,len,(p[x]<n)-(p[x]>n));
	p[x]=y;
	SGT::modify(1,1,len,x,len,(p[x]>n)-(p[x]<n));
}
int main()
{
	scanf("%d%d",&n,&m);
	len=2*n+1;
	n++;
	for(int i=1;i<=len;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=len;i++)
		updrp(p[i],i);
	SGT::build(1,1,len);
	for(int i=1;i<=len;i++)
		SGT::modify(1,1,len,i,len,(p[i]>n)-(p[i]<n));
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int x=p[u],y=p[v];
		updp(v,x);
		updrp(x,v);
		updp(u,y);
		updrp(y,u);
		int q=SGT::query(1,1,len,rp[n]);
		int mn=SGT::sum[1];
	//	printf("u=%d,v=%d,q=%d,mn=%d,sum=%lld,%lld\n",u,v,q,mn,suml,sumr);
		if(mn!=q)
		{
			printf("%d\n",SGT::sumid[1]%len);
			continue;
		}
		if(suml<len&&sumr<len)
		{
			printf("-1\n");
			continue;
		}
		if(suml>=len)
			printf("%d\n",rp[n]%len);
		else printf("%d\n",(rp[n]-1)%len);
	}
	return 0;
}