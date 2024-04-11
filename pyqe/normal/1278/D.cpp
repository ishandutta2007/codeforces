#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pr[500069];
pair<long long,long long> a[500069];
priority_queue<pair<long long,long long>> pq;
multiset<pair<long long,long long>> ms;
multiset<pair<long long,long long>>::iterator it;
bitset<500069> vtd;

long long fd(long long x)
{
	if(pr[x]!=x)
	{
		pr[x]=fd(pr[x]);
	}
	return pr[x];
}

int main()
{
	long long i,j,k,l,c=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
		pr[i]=i;
	}
	sort(a+1,a+n+1);
	for(j=1,i=1;i<=n*2;i++)
	{
		if(a[j].fr==i)
		{
			pq.push({-a[j].sc,j});
			ms.insert({a[j].fr,j});
			j++;
		}
		else if(!pq.empty()&&-pq.top().fr==i)
		{
			k=pq.top().sc;
			pq.pop();
			ms.erase(ms.find({a[k].fr,k}));
			for(it=ms.upper_bound({a[k].fr,k});it!=ms.end();it++)
			{
				l=(*it).sc;
				if(fd(k)==fd(l))
				{
					printf("NO\n");
					return 0;
				}
				pr[fd(l)]=fd(k);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[fd(i)])
		{
			c++;
			vtd[fd(i)]=1;
		}
	}
	if(c>1)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
}