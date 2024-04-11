#include <bits/stdc++.h>

using namespace std;

long long n,fq[200069];
priority_queue<long long> pq;

int main()
{
	long long t,rr,i,j,k,sm,z;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<=n;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
		}
		sm=0;
		bad=0;
		for(;!pq.empty();pq.pop());
		for(i=0;i<=n;i++)
		{
			z=-1;
			if(!bad)
			{
				z=sm+fq[i];
			}
			printf("%lld%c",z," \n"[i==n]);
			for(j=0;j<fq[i];j++)
			{
				pq.push(i);
			}
			if(pq.empty())
			{
				bad=1;
			}
			else
			{
				sm+=i-pq.top();
				pq.pop();
			}
		}
	}
}