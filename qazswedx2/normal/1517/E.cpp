#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
int t,n,a[1000005];
ll sum,b[1000005];
int solve(int l,int r,int nw)
{
	b[l-1]=0,b[l]=a[l];
	for(int i=l+1;i<=r;i++)
		b[i]=b[i-2]+a[i];
	ll ans=0;
	for(int i=l+1;i<=r;i++)
	{
		int L=0,R=(i-l-1)/2,mid;
		while(L<=R)
		{
			mid=(L+R)/2;
			if(nw+b[i-1]+b[i-(mid+1)*2]<=(sum-1)/2) R=mid-1;
			else L=mid+1;
		}
		ans+=((i-l-1)/2-L+1);
//		printf("i=%d,L=%d,%d\n",i,L,((i-l-1)/2-L+1));
	}
//	printf("solve:l=%d,r=%d,nw=%d,ans=%lld\n",l,r,nw,ans);
	return ans%mod;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum+=a[i];
		int ans=0;
		ans=addmod(ans+solve(1,n,0));
		ans=addmod(ans+solve(1,n-1,a[n]));
		ans=addmod(ans+solve(2,n,0));
		ans=addmod(ans+solve(2,n-1,a[n]));
		ll nw=0;
		for(int i=1;i<=n;i++)
		{
			nw+=a[i];
			if(nw>sum/2) ans=addmod(ans+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}