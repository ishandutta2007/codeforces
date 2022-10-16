#include <bits/stdc++.h>

using namespace std;

long long n[2],ttl=0,c=0,sm=0;
multiset<long long> pq,ms[2];
multiset<long long>::iterator it;

void blc()
{
	for(;n[0]<c&&n[1];n[0]++,n[1]--)
	{
		it=ms[1].end();
		it--;
		sm+=*it;
		ms[0].insert(*it);
		ms[1].erase(it);
	}
	for(;n[0]>c;n[0]--,n[1]++)
	{
		it=ms[0].begin();
		sm-=*it;
		ms[1].insert(*it);
		ms[0].erase(it);
	}
}

void ins(long long x)
{
	long long e=!n[0]||x<*ms[0].begin();
	
	ms[e].insert(x);
	n[e]++;
	sm+=x*!e;
}

void ers(long long x)
{
	long long e=!n[0]||x<*ms[0].begin();
	
	ms[e].erase(ms[e].find(x));
	n[e]--;
	sm-=x*!e;
}

int main()
{
	long long t,rr,i,ky,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		ttl+=k;
		if(!ky)
		{
			if(k>0)
			{
				ins(k);
			}
			else
			{
				k*=-1;
				ers(k);
			}
		}
		else
		{
			if(k>0)
			{
				if(!pq.empty())
				{
					ins(*pq.begin());
				}
				pq.insert(k);
				ins(k);
				ers(*pq.begin());
				c++;
			}
			else
			{
				k*=-1;
				ins(*pq.begin());
				pq.erase(pq.find(k));
				ers(k);
				if(!pq.empty())
				{
					ers(*pq.begin());
				}
				c--;
			}
		}
		blc();
		printf("%lld\n",ttl+sm);
	}
}