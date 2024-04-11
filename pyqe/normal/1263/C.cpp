#include <bits/stdc++.h>

using namespace std;

long long n,zs;
vector<long long> sq;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sq.clear();
		zs=0;
		sq.push_back(0);
		zs++;
		for(i=1;i*i<=n;i++)
		{
			sq.push_back(i);
			zs++;
			if(i!=n/i)
			{
				sq.push_back(n/i);
				zs++;
			}
		}
		sort(sq.begin(),sq.end());
		printf("%lld\n",zs);
		for(i=0;i<zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs-1]);
		}
	}
}