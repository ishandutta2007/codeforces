#include <bits/stdc++.h>

using namespace std;

long long n;

struct trie
{
	long long dh,sbt;
	trie *p[2];
	
	inline void bd(long long x)
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
		if(1ll<<dh<=x)
		{
			long long e=x>>dh&1;
			
			if(!p[e])
			{
				p[e]=new trie;
				p[e]->bd(dh+1);
			}
			p[e]->ins(x,w);
		}
	}
	bool chk()
	{
		long long ii;
		bool bad=sbt>0;
		
		for(ii=0;ii<2;ii++)
		{
			if(p[ii])
			{
				bad|=p[ii]->chk();
			}
		}
		return bad;
	}
}
tr;

int main()
{
	long long t,rr,i,ii,u,k,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		tr.bd(0);
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(i=0;i<n;i++)
			{
				scanf("%lld",&k);
				for(w=0;k;k>>=1)
				{
					w=w<<1|k&1;
				}
				tr.ins(w,u);
			}
		}
		if(!tr.chk())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}