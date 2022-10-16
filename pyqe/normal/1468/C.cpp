#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n=0;
priority_queue<pair<long long,long long>> pq;
bitset<500069> vtd;

int main()
{
	long long t,rr,ky,k,p=1,z;
	bool ft=1;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&ky);
		if(ky==1)
		{
			scanf("%lld",&k);
			n++;
			pq.push({k,-n});
		}
		else
		{
			if(ky==2)
			{
				for(;vtd[p];p++);
				z=p;
			}
			else
			{
				for(;vtd[-pq.top().sc];pq.pop());
				z=-pq.top().sc;
				pq.pop();
			}
			if(!ft)
			{
				printf(" ");
			}
			ft=0;
			printf("%lld",z);
			vtd[z]=1;
		}
	}
	printf("\n");
}