#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],ls[100069],nx[100069];
bitset<100069> vtd;
multiset<pair<long long,long long>> ms;
multiset<pair<long long,long long>>::iterator it;

int main()
{
	long long i,k,l,mx=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		vtd[1]=vtd[1]|a[i]>1;
	}
	if(!vtd[1])
	{
		printf("1\n");
		return 0;
	}
	for(i=1;i<=n+1;i++)
	{
		ls[i]=n+1;
	}
	for(i=n;i;i--)
	{
		nx[i]=ls[a[i]];
		ls[a[i]]=i;
	}
	for(i=1;i<=n+1;i++)
	{
		if(ls[i]>mx)
		{
			vtd[i]=1;
			ms.insert({i,ls[i]});
			mx=max(mx,ls[i]);
		}
	}
	for(i=2;i<=n;i++)
	{
		k=a[i-1];
		l=nx[i-1];
		it=ms.lower_bound({k,0});
		if(it==ms.begin()||prev(it)->sc<l)
		{
			vtd[k]=1;
			for(;it!=ms.end()&&it->sc<=l;)
			{
				it++;
				ms.erase(prev(it));
			}
			ms.insert({k,l});
		}
	}
	for(i=1;vtd[i];i++);
	printf("%lld\n",i);
}