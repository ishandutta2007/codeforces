#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[105];
int t;
int main()
{
	for(int i=1;i<=31;i++)
	{
		a[i]=(1ll<<(i))*((1ll<<(i))-1)/2;
		//printf("%lld\n",a[i]);
	}
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		for(int i=1;i<=31;i++)
			if(n>=a[i]) n-=a[i];
			else
			{
				printf("%d\n",i-1);
				break;
			}
	}
}