#include <bits/stdc++.h>

using namespace std;

long long n,fq[3],zs=0;
vector<long long> sq;

int main()
{
	long long i,ii,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(ii=2;ii;ii--)
	{
		if(fq[ii])
		{
			sq.push_back(ii);
			zs++;
		}
	}
	for(ii=2;ii;ii--)
	{
		for(i=0;i<fq[ii]-1;i++)
		{
			sq.push_back(ii);
			zs++;
		}
	}
	for(i=0;i<zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs-1]);
	}
}