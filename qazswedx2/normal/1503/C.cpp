#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int a,c;
	pt(int a=0,int c=0):a(a),c(c){}
	bool operator<(const pt x) const
	{
		return a<x.a;
	}
}a[1000005];
int n;
ll f[1000005],dp[1000005];
int main()
{
	memset(dp,0x3f,sizeof(dp));
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].a,&a[i].c);
		sum+=a[i].c;
	}
	sort(a+1,a+n+1);
	dp[1]=0;
	int las=1;
	for(int i=1;i<=n;i++)
	{
		int u=upper_bound(a+1,a+n+1,pt(a[i].a+a[i].c,0))-a;
		las=max(las,i);
		for(int j=las;j<u;j++)
			dp[j]=min(dp[j],dp[i]);
		las=u-1;
		dp[u]=min(dp[u],dp[i]+(a[u].a-a[i].a-a[i].c));
	}
	printf("%lld\n",dp[n]+sum);
	return 0;
}