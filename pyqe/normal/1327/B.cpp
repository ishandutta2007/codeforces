#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long> al;
bitset<100069> vtd;

int main()
{
	long long t,rr,i,j,k,l,sz,e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		e=0;
		for(i=1;i<=n;i++)
		{
			al.clear();
			scanf("%lld",&sz);
			for(j=0;j<sz;j++)
			{
				scanf("%lld",&k);
				al.push_back(k);
			}
			sort(al.begin(),al.end());
			for(j=0;j<sz;j++)
			{
				l=al[j];
				if(!vtd[l])
				{
					vtd[l]=1;
					j=-1;
					break;
				}
			}
			if(j!=-1)
			{
				e=i;
			}
		}
		if(!e)
		{
			printf("OPTIMAL\n");
		}
		else
		{
			for(i=1;vtd[i];i++);
			printf("IMPROVE\n%lld %lld\n",e,i);
		}
	}
}