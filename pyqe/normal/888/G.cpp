#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ttl=0;

struct trie
{
	long long dh,z,dg=0,e;
	pair<long long,long long> mxe={-1e18,0};
	trie *p[2]={0,0};
	
	void ins(long long x)
	{
		long long k;
		
		dg++;
		if(dh)
		{
			k=(x>>dh-1)%2;
			if(!p[k])
			{
				p[k]=new trie;
				p[k]->dh=dh-1;
				p[k]->z=z+(k<<dh-1);
			}
			p[k]->ins(x);
		}
	}
	long long qr(long long x)
	{
		long long ii,k;
		
		if(!dh)
		{
			return z;
		}
		else
		{
			k=(x>>dh-1)%2;
			for(ii=0;ii<2;ii++)
			{
				if(p[k^ii])
				{
					return p[k^ii]->qr(x);
				}
			}
		}
	}
	long long bf(trie *sr)
	{
		long long ii,mn=1e18;
		
		if(!dh)
		{
			return z^sr->qr(z^(1<<sr->dh));
		}
		else
		{
			for(ii=0;ii<2;ii++)
			{
				if(p[ii])
				{
					mn=min(mn,p[ii]->bf(sr));
				}
			}
			return mn;
		}
	}
	void dfs()
	{
		long long i,ii,k;
		
		for(ii=0;ii<2;ii++)
		{
			if(p[ii])
			{
				p[ii]->dfs();
				mxe=max(mxe,{p[ii]->dg,ii});
			}
		}
		e=mxe.sc;
		if(p[!e])
		{
			ttl+=p[!e]->bf(p[e]);
		}
	}
}
tr;

int main()
{
	long long i,k;
	
	
	scanf("%lld",&n);
	tr.dh=30;
	tr.z=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		tr.ins(k);
	}
	tr.dfs();
	printf("%lld\n",ttl);
}