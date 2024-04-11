#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<2> vtd;

int main()
{
	long long t,rr,i,ii,k,l;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		bad=0;
		l=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			bad|=k<l;
			l=k;
		}
		for(ii=0;ii<2;ii++)
		{
			vtd[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			vtd[k]=1;
		}
		if(!bad||(vtd[0]&&vtd[1]))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}