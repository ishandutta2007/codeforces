#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m;
ll k;
int main()
{
	scanf("%d%d%I64d",&n,&m,&k);
	ll ua=0,ub=n*1ll*m;
	while(ua<ub-1)
	{
		ll t=0;
		ll mid=ua+ub;
		mid/=2;
		for(int i=1;i<=n;i++)
		{
			ll s=mid/i;
			if(s>m)s=m;
			t+=s;
		}
		if(t>=k)
			ub=mid;
		else
			ua=mid;
	}
	printf("%I64d\n",ub);
	return 0;
}