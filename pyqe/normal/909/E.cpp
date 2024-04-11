#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dg[100069],w=0;
bitset<100069> a;
vector<long long> pr[100069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,k,l,sz;
	bool tmp;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		a[i]=tmp;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		dg[k]++;
		pr[l].push_back(k);
	}
	for(i=0;i<n;i++)
	{
		if(!dg[i])
		{
			pq.push({-w-(w+2-a[i])%2,i});
		}
	}
	for(;!pq.empty();)
	{
		k=pq.top().sc;
		w=-pq.top().fr;
		pq.pop();
		sz=pr[k].size();
		for(i=0;i<sz;i++)
		{
			l=pr[k][i];
			dg[l]--;
			if(!dg[l])
			{
				pq.push({-w-(w+2-a[l])%2,l});
			}
		}
	}
	printf("%lld\n",(w+1)/2);
}