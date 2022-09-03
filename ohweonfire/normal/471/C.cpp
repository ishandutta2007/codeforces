#include <cstdio>
using namespace std;
typedef long long ll;
ll n;
ll calc(ll c)
{
	return c*2+c*(c-1)/2*3;
}
int main()
{
	scanf("%I64d",&n);
	int tmp=3-n%3;
	ll l=1,r=2147483647ll;
	while(l<r-1)
	{
		ll mid=l+r>>1;
		if(calc(mid)>n)
			r=mid;
		else
			l=mid;
	}
	if(l<tmp)
	{
		printf("0\n");
		return 0;
	}
	while((l-1)%3+1!=tmp)
		l--;
	printf("%I64d\n",(l-tmp)/3+1);
	return 0;
}