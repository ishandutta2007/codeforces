#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],df[100069],sq[100069];
pair<long long,long long> qq[100069];

int main()
{
	long long t,rr,i,k,l,pz,sm=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	a[n+1]=2e18;
	for(i=1;i<=n;i++)
	{
		df[i]=a[i+1]-a[i];
	}
	sort(df+1,df+n+1);
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		qq[rr]={l-k+1,rr};
	}
	sort(qq+1,qq+t+1);
	for(i=0,rr=1;rr<=t;rr++)
	{
		k=qq[rr].fr;
		pz=qq[rr].sc;
		for(;df[i+1]<=k;i++)
		{
			sm+=(n-i)*(df[i+1]-df[i]);
		}
		sq[pz]=sm+(n-i)*(k-df[i]);
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld%c",sq[rr]," \n"[rr==t]);
	}
	
}