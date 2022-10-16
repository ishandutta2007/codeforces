#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,sm=0;
	bool bad=1;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		k/=100;
		sm+=k;
		bad&=k!=1;
	}
	if(sm%2==0&&(sm/2%2==0||!bad))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}