#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069][2],ttl[2];

int main()
{
	long long i,ii;
	pair<long long,long long> z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[i][ii]);
			ttl[ii]+=a[i][ii];
		}
	}
	z={abs(ttl[0]-ttl[1]),0};
	for(i=1;i<=n;i++)
	{
		z=max(z,{abs(ttl[0]-ttl[1]+(a[i][1]-a[i][0])*2),i});
	}
	printf("%lld\n",z.sc);
}