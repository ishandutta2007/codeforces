#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,c,p[100005],s[100005];
ll a[100005],ans;
int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]),ans+=p[i];
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i]-p[i]+1ll*c*(n-i);
	//	printf("i=%d,a=%d\n",i,a[i]);
	}
	sort(a+1,a+n+1);
	ll tans=ans;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i]-1ll*c*(i-1);
		tans=min(tans,ans);
	}
	printf("%lld\n",tans);
	return 0;
}