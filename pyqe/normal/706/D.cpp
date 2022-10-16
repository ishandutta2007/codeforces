#include <bits/stdc++.h>

using namespace std;

struct trie
{
	long long dh=30,lf=0;
	trie *p[2]={0,0};
	
	void ins(long long x)
	{
		long long tg=x>>dh-1&1;
		
		lf++;
		if(dh)
		{
			if(!p[tg])
			{
				p[tg]=new trie;
				p[tg]->dh=dh-1;
			}
			p[tg]->ins(x);
		}
	}
	void ers(long long x)
	{
		long long tg=x>>dh-1&1;
		
		lf--;
		if(dh)
		{
			p[tg]->ers(x);
			if(!p[tg]->lf)
			{
				p[tg]=0;
			}
		}
	}
	long long qr(long long x)
	{
		long long ii,tg=x>>dh-1&1;
		
		if(!dh)
		{
			return 0;
		}
		else
		{
			for(ii=1;ii+1;ii--)
			{
				if(p[ii^tg])
				{
					return p[ii^tg]->qr(x)+(ii<<dh-1);
				}
			}
		}
	}
}
tr;

int main()
{
	long long t,rr,k;
	char ch;
	
	tr.ins(0);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf(" %c%lld",&ch,&k);
		if(ch=='+')
		{
			tr.ins(k);
		}
		else if(ch=='-')
		{
			tr.ers(k);
		}
		else if(ch=='?')
		{
			printf("%lld\n",tr.qr(k));
		}
	}
}