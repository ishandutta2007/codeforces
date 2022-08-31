#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int n,a[100005],q,p[200005],prime[200005],pt,pn=2e5,inv[200005],f[200005];
int rt[100005],sum[40000005],ls[40000005],rs[40000005],ct,vis[200005];
void pushup(int x)
{
	sum[x]=1ll*sum[ls[x]]*sum[rs[x]]%mod;
}
int modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return x;
	int y=++ct;
	sum[y]=sum[x],ls[y]=ls[x],rs[y]=rs[x];
	if(l==r)
	{
		sum[y]=1ll*sum[y]*v%mod;
		return y;
	}
	int mid=(l+r)/2;
	ls[y]=modify(ls[y],l,mid,qx,v);
	rs[y]=modify(rs[y],mid+1,r,qx,v);
	pushup(y);
	return y;
}
int query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql||!x) return 1;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;
	return 1ll*query(ls[x],l,mid,ql,qr)*query(rs[x],mid+1,r,ql,qr)%mod;
}
int b[105],bt;
void solve(int x)
{
	bt=0;
	for(int i=1;i<=pt&&prime[i]*prime[i]<=x;i++)
		if(x%prime[i]==0)
		{
			int nw=1;
			while(x%prime[i]==0)
			{
				nw*=prime[i];
				b[++bt]=nw;
				x/=prime[i];
			}
		}
	if(x!=1) b[++bt]=x;
}
void print(int x,int l,int r)
{
	printf("x=%d,l=%d,r=%d,sum=%d\n",x,l,r,sum[x]);
	if(l==r) return;
	int mid=(l+r)/2;
	print(ls[x],l,mid);
	print(rs[x],mid+1,r);
}
int main()
{
	for(int i=1;i<=pn;i++)
		inv[i]=fpow(i,mod-2);
	sum[0]=1;
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	for(int i=1;i<=pt;i++)
	{
		int u=1;
		while(1ll*u*prime[i]<=pn)
		{
			u*=prime[i];
			f[u]=prime[i];
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		solve(a[i]);
		rt[i]=rt[i-1];
		rt[i]=modify(rt[i],1,n,i,a[i]);
		for(int j=1;j<=bt;j++)
		{
			int u=b[j];
			if(vis[u]) rt[i]=modify(rt[i],1,n,vis[u],inv[f[u]]);
			vis[u]=i;
		}
	///	printf("i=%d\n",i);
	//	print(rt[i],1,n);
	}
	scanf("%d",&q);
	int las=0;
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l=(l+las)%n+1,r=(r+las)%n+1;
		if(l>r) swap(l,r);
	//	printf("l=%d,r=%d\n",l,r);
		las=query(rt[r],1,n,l,r);
		printf("%d\n",las);
	}
	return 0;
}