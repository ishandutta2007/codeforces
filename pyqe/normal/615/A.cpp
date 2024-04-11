#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<100069> vtd;

int main()
{
	long long i,j,k,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&sz);
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&k);
			m-=!vtd[k];
			vtd[k]=1;
		}
	}
	if(!m)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}