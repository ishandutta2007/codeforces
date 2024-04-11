#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,a,b,c;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
		ll ans=2e18;
		ans=min(ans,(a-n%a)%a);
		ans=min(ans,(b-n%b)%b);
		ans=min(ans,(c-n%c)%c);
		printf("%lld\n",ans);
	}
	return 0;
}