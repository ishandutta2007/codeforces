#include<cstdio>
#include<algorithm>
using namespace std;
long long n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=k;i++)
	{
		if((n+1)%i!=0)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}