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
int n,m,a[200005],sum[20000005],ls[20000005],rs[20000005],ct;
int rt[200005],p[200005],rp[200005],prime[200005],pt,pn=2e5;
int ans=1;
void pushup(int x)
{
	sum[x]=min(sum[ls[x]],sum[rs[x]]);
}
int modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return x;
	if(!x) x=++ct;
	if(l==r)
	{
		sum[x]+=v;
		return x;
	}
	int mid=(l+r)/2;
	ls[x]=modify(ls[x],l,mid,qx,v);
	rs[x]=modify(rs[x],mid+1,r,qx,v);
	pushup(x);
	return x;
}
void tmodify(int i,int x,int v)
{
	int las=sum[rt[i]];
	rt[i]=modify(rt[i],1,n,x,v);
	if(sum[rt[i]]!=las) ans=1ll*ans*fpow(prime[i],sum[rt[i]]-las)%mod;
}
void ins(int x,int v)
{
	for(int i=1;i<=pt&&prime[i]*prime[i]<=v;i++)
		if(v%prime[i]==0)
		{
			int nw=0;
			while(v%prime[i]==0) v/=prime[i],nw++;
			tmodify(i,x,nw);
		}
	if(v!=1)
	{
		tmodify(rp[v],x,1);
	}
}
int main()
{
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
		rp[prime[i]]=i;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		ins(i,x);
	}
	for(int i=1;i<=m;i++)
	{
		int x,v;
		scanf("%d%d",&x,&v);
		ins(x,v);
		printf("%d\n",ans);
	}
	return 0;
}