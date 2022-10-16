#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;

int main()
{
	long long i,k,mx2=0;
	pair<long long,long long> mxe={0,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(k>mxe.fr)
		{
			mx2=mxe.fr;
			mxe={k,i};
		}
		else
		{
			mx2=max(mx2,k);
		}
	}
	printf("%lld %lld\n",mxe.sc,mx2);
}