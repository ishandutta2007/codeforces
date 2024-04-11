#include <bits/stdc++.h>

using namespace std;

long long n;
multiset<long long> ms[2];
multiset<long long>::iterator it;

void ins(long long x)
{
	it=ms[0].upper_bound(x);
	if(it!=ms[0].begin())
	{
		ms[1].insert(x-*prev(it));
		if(it!=ms[0].end())
		{
			ms[1].erase(ms[1].find(*it-*prev(it)));
		}
	}
	if(it!=ms[0].end())
	{
		ms[1].insert(*it-x);
	}
	ms[0].insert(x);
}

void ers(long long x)
{
	ms[0].erase(x);
	it=ms[0].upper_bound(x);
	if(it!=ms[0].begin())
	{
		ms[1].erase(ms[1].find(x-*prev(it)));
		if(it!=ms[0].end())
		{
			ms[1].insert(*it-*prev(it));
		}
	}
	if(it!=ms[0].end())
	{
		ms[1].erase(ms[1].find(*it-x));
	}
}

int main()
{
	long long t,rr,i,ky,k,z;
	
	scanf("%lld%lld",&n,&t);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		ins(k);
	}
	for(rr=0;rr<=t;rr++)
	{
		if(rr)
		{
			scanf("%lld%lld",&ky,&k);
			if(!ky)
			{
				ers(k);
			}
			else
			{
				ins(k);
			}
		}
		z=0;
		if(!ms[0].empty())
		{
			z=*prev(ms[0].end())-*ms[0].begin();
			if(!ms[1].empty())
			{
				z-=*prev(ms[1].end());
			}
		}
		printf("%lld\n",z);
	}
}