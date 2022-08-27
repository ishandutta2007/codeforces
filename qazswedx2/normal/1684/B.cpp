#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int T;
ll a,b,c;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld %lld %lld\n",a+b+c,b+c,c);
	}
	return 0;
}