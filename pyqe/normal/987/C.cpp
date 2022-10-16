#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],wg[100069],inf=1e18;
multiset<pair<long long,long long>> ms[4];
multiset<pair<long long,long long>>::iterator it,et;

int main()
{
	long long i,j,k,l,w;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",wg+i);
	}
	ms[0].insert({-inf,0});
	for(i=1;i<=n;i++)
	{
		for(j=3;j;j--)
		{
			it=ms[j-1].lower_bound({a[i],-inf});
			if(it!=ms[j-1].begin())
			{
				it--;
				w=(*it).sc+wg[i];
				it=ms[j].upper_bound({a[i],inf});
				if(it==ms[j].begin())
				{
					k=inf;
				}
				else
				{
					it--;
					k=(*it).sc;
				}
				if(w<k)
				{
					ms[j].insert({a[i],w});
					for(it=ms[j].upper_bound({a[i],w});it!=ms[j].end();)
					{
						k=(*it).sc;
						if(k>=w)
						{
							et=it;
							it++;
							ms[j].erase(et);
						}
						else
						{
							break;
						}
					}
				}
			}
		}
	}
	it=ms[3].end();
	if(it==ms[3].begin())
	{
		printf("-1\n");
	}
	else
	{
		it--;
		printf("%lld\n",(*it).sc);
	}
}