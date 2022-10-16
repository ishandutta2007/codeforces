#include <bits/stdc++.h>

using namespace std;

long long n,fq[200069],sz;
vector<long long> sq;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=0;i<=200000;i++)
	{
		if(fq[i]>2)
		{
			printf("NO\n");
			return 0;
		}
		if(fq[i])
		{
			sq.push_back(i);
			sz++;
			fq[i]--;
		}
	}
	printf("YES\n");
	printf("%lld\n",sz);
	for(i=0;i<sz;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==sz-1]);
	}
	sq.clear();
	sz=0;
	for(i=200000;i>=0;i--)
	{
		if(fq[i])
		{
			sq.push_back(i);
			sz++;
			fq[i]--;
		}
	}
	printf("%lld\n",sz);
	for(i=0;i<sz;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==sz-1]);
	}
}