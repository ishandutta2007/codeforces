#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],sq[200069];
pair<long long,long long> as[200069];

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1,greater<long long>());
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		as[i]={k,i};
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		sq[as[i].sc]=a[i];
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}