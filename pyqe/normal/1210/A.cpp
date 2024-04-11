#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[8],z,mx=-1e18;
pair<long long,long long> ed[69];
map<pair<long long,long long>,bool> vtd;

void bf(long long x)
{
	for(a[x]=1;a[x]<=6;a[x]++)
	{
		if(x==n)
		{
			long long i,k,l,ls=mx;
			
			vtd.clear();
			z=0;
			for(i=1;i<=m;i++)
			{
				k=ed[i].fr;
				l=ed[i].sc;
				if(a[k]>a[l])
				{
					swap(k,l);
				}
				z+=!vtd[{a[k],a[l]}];
				vtd[{a[k],a[l]}]=1;
			}
			mx=max(mx,z);
		}
		else
		{
			bf(x+1);
		}
	}
}

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&ed[i].fr,&ed[i].sc);
	}
	bf(1);
	printf("%lld\n",mx);
}