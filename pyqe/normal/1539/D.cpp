#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[100069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,j,k,l,w,w2,p,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		z+=k;
		a[i]={l,k};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=a[i].fr;
		pq.push({k,i});
	}
	for(j=1,i=1;i<=n;i++)
	{
		w=a[i].fr-a[i-1].fr;
		for(;j<i;j++)
		{
			w2=min(a[j].sc,w);
			w-=w2;
			a[j].sc-=w2;
			if(!w)
			{
				break;
			}
		}
		for(;w&&!pq.empty();)
		{
			k=pq.top().fr;
			p=pq.top().sc;
			pq.pop();
			if(p<i)
			{
				continue;
			}
			w2=min(a[p].sc,w);
			z+=w2;
			w-=w2;
			a[p].sc-=w2;
			if(a[p].sc)
			{
				pq.push({k,p});
			}
		}
	}
	printf("%lld\n",z);
}