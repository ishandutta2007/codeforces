#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,z[200069];
multiset<pair<long long,long long>> ms;
multiset<pair<long long,long long>>::iterator it;

int main()
{
	long long i,k,pz,c;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ms.insert({k,i});
	}
	for(c=1;!ms.empty();c++)
	{
		for(it=ms.begin();it!=ms.end();)
		{
			k=(*it).fr;
			pz=(*it).sc;
			ms.erase(it);
			z[pz]=c;
			it=ms.upper_bound({k+d,n+1});
		}
	}
	printf("%lld\n",c-1);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",z[i]," \n"[i==n]);
	}
}