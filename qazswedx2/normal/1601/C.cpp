#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int bt;
namespace BIT
{
	int sum[2000005];
	inline int lowbit(int x)
	{
		return x&-x;
	}
	void modify(int x,int v)
	{
		for(int i=x;i;i-=lowbit(i))
			sum[i]+=v;
	}
	int query(int x)
	{
		int ans=0;
		for(int i=x;i<=bt;i+=lowbit(i))
			ans+=sum[i];
		return ans;
	}
}
int t,n,m,a[2000005],b[2000005],f[2000005],p[2000005],c[2000005];
int sum[10000005],suml[10000005],ls[10000005],rs[10000005],ct,tans[2000005];
void pushup(int x)
{
	sum[x]=sum[ls[x]]+sum[rs[x]];
	suml[x]=max(suml[ls[x]],suml[rs[x]]+sum[ls[x]]);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=-1;
		suml[x]=0;
		return;
	}
	ls[x]=x*2,rs[x]=x*2+1;
	int mid=(l+r)/2;
	build(ls[x],l,mid);
	build(rs[x],mid+1,r);
	pushup(x);
}
int modify(int x,int l,int r,int qx)
{
	if(l>qx||r<qx) return x;
	int y=x;
	if(l==r)
	{
		sum[y]++;
		suml[y]=max(sum[y],suml[y]);
		return y;
	}
	int mid=(l+r)/2;
	ls[y]=modify(ls[x],l,mid,qx);
	rs[y]=modify(rs[x],mid+1,r,qx);
	pushup(y);
	//printf("modify:x=%d,l=%d,r=%d,sum=%d,suml=%d,qx=%d\n",x,l,r,sum[x],suml[x],qx);
	return y;
}
bool cmp(const int x,const int y)
{
	if(a[x]!=a[y]) return a[x]<a[y];
	return x<y;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		bt=ct=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[++bt]=a[i];
			c[i]=i;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&p[i]);
			b[++bt]=p[i];
		}
		sort(b+1,b+bt+1);
		bt=unique(b+1,b+bt+1)-b-1;
		build(1,1,n);
		ll ans=0;
		for(int i=1;i<=n;i++)
			a[i]=lower_bound(b+1,b+bt+1,a[i])-b;
		for(int i=1;i<=n;i++)
		{
			ans+=BIT::query(a[i]+1);
			BIT::modify(a[i],1);
		}
		for(int i=1;i<=n;i++)
			BIT::modify(a[i],-1);
		sort(c+1,c+n+1,cmp);
		int nw=1;
		tans[0]=0;
		for(int i=1;i<=bt;i++)
		{
			int las=nw;
			while(nw<=n&&a[c[nw]]<=i)
			{
				int u=c[nw];
				modify(1,1,n,u);
				nw++;
			}
			nw=las;
			tans[i]=(nw-1)-suml[1];
		//	printf("i=%d,b=%d,a=%d,nw=%d,suml=%d,tans=%d\n",i,b[i],a[c[nw]],nw,suml[1],tans[i]);
			while(nw<=n&&a[c[nw]]<=i)
			{
				int u=c[nw];
				modify(1,1,n,u);
				nw++;
			}
		}
	//	printf("ans=%lld\n",ans);
		for(int i=1;i<=m;i++)
		{
			int q=lower_bound(b+1,b+bt+1,p[i])-b;
			ans+=tans[q];
	//		printf("i=%d,q=%d,ans=%lld\n",i,q,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}