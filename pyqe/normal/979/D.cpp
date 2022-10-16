#include <bits/stdc++.h>

using namespace std;

long long n,ma=1e5,inf=1e18;
vector<long long> fz[100069];
bitset<100069> vtd;

struct trie
{
	long long dh,mn;
	trie *p[2];
	
	void bd(long long x)
	{
		long long ii;
		
		dh=x;
		mn=inf;
		for(ii=0;ii<2;ii++)
		{
			p[ii]=0;
		}
	}
	void ins(long long x)
	{
		mn=min(mn,x);
		if(dh)
		{
			long long e=x>>dh-1&1;
			
			if(!p[e])
			{
				p[e]=new trie;
				p[e]->bd(dh-1);
			}
			p[e]->ins(x);
		}
	}
	long long qr(long long x,long long w)
	{
		if(dh)
		{
			long long e=!(x>>dh-1&1);
			
			return p[e^(!p[e]||p[e]->mn>w)]->qr(x,w);
		}
		else
		{
			return mn;
		}
	}
}
tr[100069];

int main()
{
	long long t,rr,i,j,ky,k,l,w,sz;
	
	for(i=1;i<=ma;i++)
	{
		for(j=i;j<=ma;j+=i)
		{
			fz[j].push_back(i);
		}
		tr[i].bd(17);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			if(!vtd[k])
			{
				vtd[k]=1;
				sz=fz[k].size();
				for(i=0;i<sz;i++)
				{
					l=fz[k][i];
					tr[l].ins(k);
				}
			}
		}
		else
		{
			scanf("%lld%lld",&l,&w);
			if(k%l||tr[l].mn>w-k)
			{
				printf("-1\n");
				continue;
			}
			printf("%lld\n",tr[l].qr(k,w-k));
		}
	}
}