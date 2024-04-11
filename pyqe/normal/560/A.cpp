#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k;
	bool bad=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		bad|=k==1;
	}
	printf("%lld\n",(long long)!bad*2-1);
}