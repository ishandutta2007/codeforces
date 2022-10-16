#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sq[100069];
pair<long long,long long> a[100069];

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]={k,i};
	}
	sort(a+1,a+n+1,greater<pair<long long,long long>>());
	for(j=1,i=1;i<=n;i++)
	{
		for(;a[j].fr>a[i].fr;j++);
		sq[a[i].sc]=j;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}