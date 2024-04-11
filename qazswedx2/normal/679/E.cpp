#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
int n,m,a[100005],pn=11,sumid[500005],lazy2[500005];
ll sum[500005],sum2[500005],pw[15],lazy[500005];
set<int> st;
void getsum(int x)
{
	sum2[x]=sum[x]-*lower_bound(pw+1,pw+pn+1,sum[x]);
}
void pushup(int x)
{
	sum2[x]=max(sum2[x*2],sum2[x*2+1]);
	sum[x]=max(sum[x*2],sum[x*2+1]);
	if(sum2[x]==sum2[x*2]) sumid[x]=sumid[x*2];
	else sumid[x]=sumid[x*2+1];
}
void col(int x,ll v)
{
	sum2[x]+=v;
	sum[x]+=v;
	lazy[x]+=v;
}
void col2(int x)
{
	sum[x]=1e17;
	getsum(x);
	lazy[x]=0;
	lazy2[x]=1;
}
void pushdown(int x)
{
	if(lazy2[x])
	{
		col2(x*2);
		col2(x*2+1);
		lazy2[x]=0;
	}
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
		sum[x]=a[l];
		getsum(x);
		sumid[x]=l;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col2(x);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr);
	modify(x*2+1,mid+1,r,ql,qr);
	pushup(x);
}
void modifyp(int x,int l,int r,int qx,ll v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]=v;
		getsum(x);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	modifyp(x*2,l,mid,qx,v);
	modifyp(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
void modifya(int x,int l,int r,int ql,int qr,ll v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,v);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	modifya(x*2,l,mid,ql,qr,v);
	modifya(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
ll query(int x,int l,int r,int qx)
{
	if(l>qx||r<qx) return 0;
	if(l==r) return sum[x];
	pushdown(x);
	int mid=(l+r)/2;
	return query(x*2,l,mid,qx)+query(x*2+1,mid+1,r,qx);
}
void querysum2(int x,int l,int r,int ql,int qr,ll &ans,int &id)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		if(sum2[x]>ans)
		{
			ans=sum2[x];
			id=sumid[x];
		}
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	querysum2(x*2,l,mid,ql,qr,ans,id);
	querysum2(x*2+1,mid+1,r,ql,qr,ans,id);
	pushup(x);
}
void check(int x)
{
	int u=*st.lower_bound(x);
	if(u!=x)
	{
		st.insert(x);
		modifyp(1,1,n,x,query(1,1,n,u));
	}
}
void print(int x,int l,int r)
{
	printf("x=%d,l=%d,r=%d,sum=%lld,sum2=%lld\n",x,l,r,sum[x],sum2[x]);
	if(l==r) return;
	pushdown(x);
	int mid=(l+r)/2;
	print(x*2,l,mid);
	print(x*2+1,mid+1,r);
}
int main()
{
	pw[0]=1;
	for(int i=1;i<=pn;i++)
		pw[i]=pw[i-1]*42;
	//for(int i=1;i<=pn;i++)
	//	printf("i=%d,pw=%lld,%d\n",i,pw[i],pw[i]>1e18);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=n;i++)
		st.insert(i);
//	print(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,l,r,x;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			int u=*st.lower_bound(x);
			printf("%lld\n",query(1,1,n,u));
			continue;
		}
		scanf("%d%d%d",&l,&r,&x);
		if(l-1) check(l-1);
		check(r);
		if(op==2)
		{
			modify(1,1,n,l,r-1);
			modifyp(1,1,n,r,x);
			while(1)
			{
				set<int>::iterator it;
				it=st.lower_bound(l);
				if(it==st.end()||*it>=r) break;
				st.erase(it);
			}
		}
		else
		{
			while(1)
			{
				modifya(1,1,n,l,r,x);
			//	printf("---");
			//	print(1,1,n);
				while(sum2[1]>0)
				{
					int u=sumid[1];
					modifyp(1,1,n,u,query(1,1,n,u));
				//	printf("***");
				}
				ll ans=-1e18;
				int id=0;
				querysum2(1,1,n,l,r,ans,id);
				if(ans<0) break;
			}
		}
	}
	return 0;
}