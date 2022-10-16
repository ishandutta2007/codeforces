#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,a[100069],z;
multiset<pair<long long,long long>> ms;

inline void ins(long long x,long long w)
{
	multiset<pair<long long,long long>>::iterator it;
	
	it=ms.upper_bound({x,inf});
	if(it==ms.begin()||w<prev(it)->sc)
	{
		for(it=ms.lower_bound({x,-inf});it!=ms.end()&&it->sc>=w;)
		{
			it++;
			ms.erase(prev(it));
			z--;
		}
		ms.insert({x,w});
		z++;
	}
}

int main()
{
	long long tt,rrr,t,rr,i,k,l;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld",&n,&t);
		ms.clear();
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ins(i,a[i]);
		}
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld%lld",&k,&l);
			a[k]-=l;
			ins(k,a[k]);
			printf("%lld%c",z," \n"[rr==t-1]);
		}
	}
}