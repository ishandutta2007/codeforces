#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,c[100005];
ll a[100005],b[100005];
bool cmp(const int x,const int y)
{
	return b[x]>b[y];
}
int main()
{
	scanf("%d",&n);
	ll sum=0,ans=0;
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&b[i]),sum+=a[i];
	for(int i=1;i<=n;i++)
		c[i]=i;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int u=c[i];
		ll nw=min(max(sum-b[u],0ll),a[u]);
		ans+=nw+(a[u]-nw)*2;
		sum-=nw;
	}
	printf("%lld\n",ans);
	return 0;
}