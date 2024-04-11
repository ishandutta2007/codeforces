#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int tree[6000010],lazy[6000010],ls[6000010],rs[6000010],b[100010],st[100010][20],n,k,q,ord,l,r,x,tot,root;
void make_st()
{
	for(int i=1;i<=n;i++)st[i][0]=b[i];
	for(int j=1;j<=20;j++)
	for(int i=1;i+(1<<j)-1<=n;i++)
	st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int get(int l,int r)
{
	int len=(int)(log(r-l+1)/log(2));
	return min(st[l][len],st[r-(1<<len)+1][len]);
}
void modify2(int &p,int x)
{
	if(!p)
	{
		p=++tot;
		tree[p]=2000000000;
		lazy[p]=-1;
	}
	tree[p]=x;
	lazy[p]=x;
}
int query(int p,int le,int ri,int ll,int rr)
{
	if(!p)
	{
		if(rr-ll+1>=n)return get(1,n);
		else if((rr-1)/n!=(ll-1)/n)return min(get((ll-1)%n+1,n),get(1,(rr-1)%n+1));
		else return get((ll-1)%n+1,(rr-1)%n+1);
	}
	if(le==ll&&ri==rr)return tree[p];
	if(lazy[p]!=-1)
	{
		modify2(ls[p],lazy[p]);
		modify2(rs[p],lazy[p]);
		lazy[p]=-1;
	}
	int mid=(le+ri)>>1;
	if(ll>mid)return query(rs[p],mid+1,ri,ll,rr);
	else if(rr<=mid)return query(ls[p],le,mid,ll,rr);
	else return min(query(ls[p],le,mid,ll,mid),query(rs[p],mid+1,ri,mid+1,rr));
}
void modify(int &p,int le,int ri,int ll,int rr,int x)
{
	if(!p)
	{
		p=++tot;
		tree[p]=2000000000;
		lazy[p]=-1;
	}
	if(le==ll&&ri==rr)
	{
		modify2(p,x);
		return;
	}
	if(lazy[p]!=-1)
	{
		modify2(ls[p],lazy[p]);
		modify2(rs[p],lazy[p]);
		lazy[p]=-1;
	}
	int mid=(le+ri)>>1;
	if(ll>mid)modify(rs[p],mid+1,ri,ll,rr,x);
	else if(rr<=mid)modify(ls[p],le,mid,ll,rr,x);
	else
	{
		modify(ls[p],le,mid,ll,mid,x);
		modify(rs[p],mid+1,ri,mid+1,rr,x);
	}
	tree[p]=min(query(ls[p],le,mid,le,mid),query(rs[p],mid+1,ri,mid+1,ri));
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	make_st();
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&ord);
		if(ord==1)
		{
			scanf("%d%d%d",&l,&r,&x);
			modify(root,1,n*k,l,r,x);
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",query(root,1,n*k,l,r));
		}
	}
	return 0;
}