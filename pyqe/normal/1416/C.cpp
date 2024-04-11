#include <bits/stdc++.h>

using namespace std;

long long n,dp[30][2];

struct trie
{
	long long dh,fq[2];
	trie *p[2];
	
	void bd(long long x)
	{
		long long ii;
		
		dh=x;
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=0;
			p[ii]=0;
		}
	}
	void ins(long long x)
	{
		if(dh)
		{
			long long e=x>>dh-1&1;
			
			if(!p[e])
			{
				p[e]=new trie;
				p[e]->bd(dh-1);
			}
			p[e]->ins(x);
			fq[e]++;
			dp[dh-1][e]+=fq[!e];
		}
	}
}
tr;


int main()
{
	long long i,k,z=0,z2=0;
	
	scanf("%lld",&n);
	tr.bd(30);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		tr.ins(k);
	}
	for(i=0;i<30;i++)
	{
		z+=min(dp[i][0],dp[i][1]);
		z2|=(dp[i][1]<dp[i][0])<<i;
	}
	printf("%lld %lld\n",z,z2);
}