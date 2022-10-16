#include <bits/stdc++.h>

using namespace std;

const long long ub=4e7;
long long n;
queue<long long> q[2];

int main()
{
	long long i,ii,k,sz,e;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld",&sz);
		for(i=0;i<sz;i++)
		{
			scanf("%lld",&k);
			q[ii].push(k);
		}
	}
	for(i=1;i<=ub;i++)
	{
		e=q[1].front()>q[0].front();
		q[e].push(q[!e].front());
		q[e].push(q[e].front());
		for(ii=0;ii<2;ii++)
		{
			q[ii].pop();
		}
		for(ii=0;ii<2;ii++)
		{
			if(q[ii].empty())
			{
				printf("%lld %lld\n",i,1ll+!ii);
				return 0;
			}
		}
	}
	printf("-1\n");
}