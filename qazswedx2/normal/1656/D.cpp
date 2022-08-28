#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int T;
ll n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ll m=n,q=1;
		while(m%2==0) m/=2,q*=2;
		if(m==1) printf("-1\n");
		else
		{
			if(m<2*q) printf("%lld\n",m);
			else printf("%lld\n",q*2);
		}
	}
}