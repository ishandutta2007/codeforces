#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,sz[5000005],lsum[5000005],rsum[5000005],a[1000005],c[1000005];
char s[1000005];
ll sum[5000005],ans;
void pushup(int x)
{
	int ls=x*2,rs=x*2+1;
	sum[x]=sum[ls]+sum[rs]+1ll*lsum[rs]*rsum[ls];
	sz[x]=sz[ls]+sz[rs];
	if(sz[ls]) lsum[x]=lsum[ls];
	else lsum[x]=lsum[ls]+lsum[rs];
	if(sz[rs]) rsum[x]=rsum[rs];
	else rsum[x]=rsum[ls]+rsum[rs];
}
void col(int x,int v)
{
	if(!v)
	{
		sz[x]=0;
		sum[x]=lsum[x]=rsum[x]=1;
	}
	else
	{
		sz[x]=1;
		sum[x]=lsum[x]=rsum[x]=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		col(x,s[l]-'0');
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int qx,int v)
{
//	if(x==1) printf("modify:qx=%d,v=%d\n",qx,v);
	if(l>qx||r<qx) return;
	if(l==r)
	{
		col(x,v);
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
bool cmp(const int x,const int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d%s",&n,s+1);
	build(1,1,n);
	for(int i=n;i>0;i--)
		if(s[i]=='1') a[i]=a[i+1]+1;
		else a[i]=0;
	for(int i=1;i<=n;i++)
		c[i]=i;
	sort(c+1,c+n+1,cmp);
	int nw=1;
	while(nw<=n&&!a[c[nw]]) nw++;
	for(int i=1;i<=n;i++)
	{
	//	printf("i=%d,sum=%d,ans=%d\n",i,sum[1],1ll*(n-i+1)*(n-i+2)/2-sum[1]);
		ans+=1ll*(n-i+1)*(n-i+2)/2-sum[1];
		while(nw<=n&&a[c[nw]]==i)
		{
			modify(1,1,n,c[nw],0);
			nw++;
		}
		modify(1,1,n,n-i+1,1);
	}
	printf("%lld\n",ans);
	return 0;
}