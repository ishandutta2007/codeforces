#include <bits/stdc++.h>

using namespace std;

long long n,a[300069];

struct trie
{
	long long dh,dp[2];
	trie *p[2];
	
	void bd(long long cdh)
	{
		long long ii;
		
		dh=cdh;
		for(ii=0;ii<2;ii++)
		{
			p[ii]=0;
			dp[ii]=0;
		}
	}
	void ins(long long x,long long w)
	{
		if(dh>=0)
		{
			long long e=(x^a[x])>>dh&1,e2=x>>dh&1;
			
			if(!p[e])
			{
				p[e]=new trie;
				p[e]->bd(dh-1);
			}
			p[e]->ins(x,w);
			p[e]->dp[e2]=max(p[e]->dp[e2],w);
		}
	}
	long long qr(long long x)
	{
		if(dh>=0)
		{
			long long w=0,e=(x^a[x])>>dh&1,e2=a[x]>>dh&1;
			
			if(p[!e])
			{
				w=p[!e]->dp[!e2];
			}
			if(!p[e])
			{
				p[e]=new trie;
				p[e]->bd(dh-1);
			}
			return max(w,p[e]->qr(x));
		}
		else
		{
			return 0;
		}
	}
}
tr;

int main()
{
	long long t,rr,i,w,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		tr.bd(29);
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",a+i);
			w=tr.qr(i)+1;
			z=max(z,w);
			tr.ins(i,w);
		}
		printf("%lld\n",z);
	}
}