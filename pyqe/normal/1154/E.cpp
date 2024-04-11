#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,sq[200069];
multiset<long long> ms;
multiset<long long>::iterator it,et,ct;
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,j,ii,k,c=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ms.insert(i);
		pq.push({k,i});
	}
	for(ii=0;c<n;ii^=1)
	{
		for(;sq[pq.top().sc];pq.pop());
		k=pq.top().sc;
		ct=ms.find(k);
		if(ct!=ms.begin())
		{
			for(j=0,it=ct,it--;j<d;j++)
			{
				sq[*it]=ii+1;
				c++;
				et=it;
				if(it==ms.begin())
				{
					ms.erase(et);
					break;
				}
				it--;
				ms.erase(et);
			}
		}
		for(j=0,it=ct;it!=ms.end()&&j<d+1;j++)
		{
			sq[*it]=ii+1;
			c++;
			et=it;
			it++;
			ms.erase(et);
		}
		
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld",sq[i]);
	}
	printf("\n");
}