#include <bits/stdc++.h>

using namespace std;

long long n,ps[100069];

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ps[i]=ps[i-1]+k;
	}
	ps[n+1]=ps[n];
	for(i=1;i<=n;i++)
	{
		if((ps[i-1]<=ps[n]-ps[i]&&ps[i]>=ps[n]-ps[i])||(ps[i]>ps[n]-ps[i+1]&&ps[i]<=ps[n]-ps[i]))
		{
			break;
		}
	}
	printf("%lld %lld\n",i,n-i);
}