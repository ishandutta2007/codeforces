#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,c;
multiset<pair<long long,long long>> ms;
multiset<pair<long long,long long>>::iterator it;

long long am(long long lh,long long rh)
{
	return (rh-lh+2)/(d+1);
}

int main()
{
	long long i,t,k,lh,rh;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&t);
	ms.insert({1,n});
	c=am(1,n);
	ms.insert({n+1,n+1});
	for(i=1;i<=t;i++)
	{
		scanf("%lld",&k);
		it=ms.upper_bound({k,n+1});
		it--;
		lh=(*it).fr;
		rh=(*it).sc;
		ms.erase(it);
		c-=am(lh,rh);
		ms.insert({lh,k-1});
		c+=am(lh,k-1);
		ms.insert({k+1,rh});
		c+=am(k+1,rh);
		if(c<m)
		{
			printf("%lld\n",i);
			return 0;
		}
	}
	printf("-1\n");
}