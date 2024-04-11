#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],sq[100069];
pair<long long,long long> as[100069];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			as[i]={a[i]-a[i-1],i};
		}
		sort(as+1,as+n+1);
		for(i=1;i<=n;i++)
		{
			sq[n+1-i]=as[i].sc;
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}