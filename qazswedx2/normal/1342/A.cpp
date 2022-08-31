#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
int t,a,b,c1,c2;
ll ans=0;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c1,&c2);
		c2=min(c2,2*c1);
		if(a<0&&b<0) a=-a,b=-b;
		if(a>0&&b>0)
		{
			printf("%lld\n",1ll*min(a,b)*c2+1ll*(a+b-2ll*min(a,b))*c1);
		}
		else printf("%lld\n",1ll*(a+b)*c1);
	}
	return 0;
}