#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,a,b,c,d;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(1ll*b*c<a)
		{
			printf("-1\n");
			continue;
		}
		int nw=(a-1)/b/d;
		ll ans;
		ans=1ll*(nw+1)*a;
		ans-=1ll*b*d*(nw+1)*nw/2;
		printf("%lld\n",ans);
	}
	return 0;
}