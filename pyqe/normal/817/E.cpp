#include <bits/stdc++.h>

using namespace std;

struct trie
{
	long long dh,sbt;
	trie *p[2];
	
	void bd(long long x)
	{
		long long ii;
		
		dh=x;
		sbt=0;
		for(ii=0;ii<2;ii++)
		{
			p[ii]=0;
		}
	}
	void ins(long long x,long long w)
	{
		sbt+=w;
		if(dh+1)
		{
			long long e=x>>dh&1;
			
			if(!p[e])
			{
				p[e]=new trie;
				p[e]->bd(dh-1);
			}
			p[e]->ins(x,w);
		}
	}
	long long qr(long long x,long long w)
	{
		if(dh+1)
		{
			long long ii,e=x>>dh&1,ee=w>>dh&1;
			
			for(ii=0;ii<2;ii++)
			{
				if(!p[ii])
				{
					p[ii]=new trie;
					p[ii]->bd(dh-1);
				}
			}
			return p[!ee^e]->sbt*ee+p[ee^e]->qr(x,w);
		}
		else
		{
			return sbt;
		}
	}
}
tr;

int main()
{
	long long t,rr,ky,k,l;
	
	scanf("%lld",&t);
	tr.bd(26);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			tr.ins(k,1);
		}
		else if(ky==2)
		{
			tr.ins(k,-1);
		}
		else
		{
			scanf("%lld",&l);
			printf("%lld\n",tr.qr(k,l-1));
		}
	}
}