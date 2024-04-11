#include <bits/stdc++.h>

using namespace std;

long long n,dg[200069];
vector<long long> al[200069];
multiset<long long> ms;

int main()
{
	long long t,rr,i,j,k,l,l2,sz,c,z;
	multiset<long long>::iterator it;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",dg+i);
			for(j=0;j<dg[i];j++)
			{
				scanf("%lld",&k);
				al[k].push_back(i);
			}
		}
		ms.clear();
		for(i=1;i<=n;i++)
		{
			if(!dg[i])
			{
				ms.insert(i);
			}
		}
		z=1;
		for(c=0,l=0;c<n;l=k,c++)
		{
			it=ms.upper_bound(l);
			if(it==ms.end())
			{
				z++;
				it=ms.begin();
			}
			if(it==ms.end())
			{
				break;
			}
			k=*it;
			ms.erase(it);
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l2=al[k][i];
				dg[l2]--;
				if(!dg[l2])
				{
					ms.insert(l2);
				}
			}
		}
		if(c<n)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}