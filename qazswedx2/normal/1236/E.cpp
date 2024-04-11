#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,sum[3000005],sum2[3000005],val=8e5,pn=2e5;
int a[1000005];
void pushup(int x)
{
	sum[x]=max(sum[x*2],sum[x*2+1]);
	sum2[x]=min(sum2[x*2],sum2[x*2+1]);
}
void modify(int x,int l,int r,int qx,int v,int fl)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		if(fl==1) sum[x]=max(v,sum[x]);
		else sum2[x]=min(v,sum2[x]);
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v,fl);
	modify(x*2+1,mid+1,r,qx,v,fl);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr,int fl)
{
	if(l>qr||r<ql) return fl==1?0:1e9;
	if(ql<=l&&r<=qr) return fl==1?sum[x]:sum2[x];
	int mid=(l+r)/2,q1,q2;
	q1=query(x*2,l,mid,ql,qr,fl);
	q2=query(x*2+1,mid+1,r,ql,qr,fl);
	return fl==1?max(q1,q2):min(q1,q2);
}
int main()
{
	memset(sum2,0x3f,sizeof(sum2));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		modify(1,1,val,i+pn,i-1,1);
		modify(1,1,val,i,i+1,2);
	}
	for(int i=1;i<=m;i++)
	{
		int q1=query(1,1,val,1,pn+a[i]-i+1,1),q2;
		modify(1,1,val,pn+a[i]-i,q1,1);
		q2=query(1,1,val,a[i]+i-1,val,2);
		modify(1,1,val,a[i]+i,q2,2);
	//	printf("i=%d,q1=%d,q2=%d\n",i,q1,q2);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int l,r;
		l=query(1,1,val,1,pn+i-(m+1),1)+1;
		r=query(1,1,val,i+(m+1),val,2)-1;
		r=min(r,n);
		ans+=r-l+1;
	//	printf("i=%d,l=%d,r=%d\n",i,l,r);
	}
	printf("%lld\n",ans);
	return 0;
}