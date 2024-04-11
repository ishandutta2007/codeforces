#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,k,c=0,b=0;
	map<long long,long long> m;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(m[k]==0)
		{
			c++;
		}
		m[k]++;
		b=max(m[k],b);
	}
	printf("%lld %lld\n",b,c);
}