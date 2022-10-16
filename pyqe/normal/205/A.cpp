#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n;

int main()
{
	long long i,k,mn=inf,e;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(k<mn)
		{
			mn=k;
			e=-1;
		}
		if(k==mn)
		{
			if(e==-1)
			{
				e=i;
			}
			else
			{
				e=-2;
			}
		}
	}
	if(e!=-2)
	{
		printf("%lld\n",e);
	}
	else
	{
		printf("Still Rozdil\n");
	}
}