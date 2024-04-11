#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,sq[100069];
pair<long long,long long> as[100069];

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			as[i]={k,i};
		}
		sort(as+1,as+n+1);
		for(i=1;i<=n;i++)
		{
			k=as[i].sc;
			sq[k]=(i-1)%m+1;
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}