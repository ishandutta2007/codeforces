#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int l,r,id;
	bool operator<(const pt p) const
	{
		return r<p.r;
	}
}p[200005];
int n,m,q,a[200005],rt[22],lazy[10000005],ls[10000005],rs[10000005],ct;
int b[200005],qans[200005];
void col(int x)
{
	lazy[x]^=1;
}
void pushdown(int x)
{
	if(lazy[x])
	{
		if(!ls[x]) ls[x]=++ct;
		if(!rs[x]) rs[x]=++ct;
		col(ls[x]);
		col(rs[x]);
		lazy[x]=0;
	}
}
int modify(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return x;
	if(!x) x=++ct;
	if(ql<=l&&r<=qr)
	{
		col(x);
		return x;
	}
	pushdown(x);
	int mid=(l+r)/2;
	ls[x]=modify(ls[x],l,mid,ql,qr);
	rs[x]=modify(rs[x],mid+1,r,ql,qr);
	return x;
}
int query(int x,int l,int r,int qx)
{
	if(l==r) return lazy[x];
	pushdown(x);
	int mid=(l+r)/2;
	if(qx<=mid) return query(ls[x],l,mid,qx);
	return query(rs[x],mid+1,r,qx);
}
void ins(int x)
{
	for(int i=0;i<=17;i++)
	{
		int u=x&((1<<(i+1))-1);
		if(x&(1<<i))
		{
			rt[i]=modify(rt[i],0,(1<<(i+1))-1,u+1,(1<<(i+1))-1);
			rt[i]=modify(rt[i],0,(1<<(i+1))-1,0,u-(1<<i));
		}
		else
		{
			rt[i]=modify(rt[i],0,(1<<(i+1))-1,u+1,u+(1<<i));
		}
	}
}
int tquery(int x)
{
	int ans=0;
	for(int i=0;i<=17;i++)
	{
		int u=x&((1<<(i+1))-1);
		ans+=query(rt[i],0,(1<<(i+1))-1,u)<<i;
	}
	return ans;
}
int tmp[200005],t;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r<n&&a[r+1]==a[l]) r++;
		if((r-l+1)%2) tmp[++t]=a[l];
	}
	for(int i=1;i<=t;i++)
		a[i]=tmp[i];
	n=t;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&p[i].l,&p[i].r);
		p[i].id=i;
		p[i].r=upper_bound(a+1,a+n+1,p[i].r)-a-1;
	}
	sort(p+1,p+q+1);
	int nw=1,bt=0;
	while(nw<=q&&!p[nw].r) nw++;
	for(int i=1;i<=n;i++)
	{
		while(bt+1<=a[i])
		{
			bt++;
			b[bt]=tquery(bt);
		}
		ins(a[i]);
		while(nw<=q&&p[nw].r==i)
		{
			int l=p[nw].l;
			int nans=b[l]^tquery(l);
			if(bt<l) nans=0;
			if(nans) qans[p[nw].id]=1;
			else qans[p[nw].id]=0;
			nw++;
		}
	}
	for(int i=1;i<=q;i++)
		if(qans[i]) printf("A");
		else printf("B");
	return 0;
}