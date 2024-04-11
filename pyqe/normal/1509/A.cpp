#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[100069];

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[i]={k%2,k};
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",a[i].sc," \n"[i==n]);
		}
	}
}