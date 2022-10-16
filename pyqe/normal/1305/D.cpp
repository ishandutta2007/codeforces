#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pr[1069];
vector<long long> al[1069];
queue<pair<long long,long long>> q;
bitset<1069> vtd;

int main()
{
	long long i,ii,k,l,w,sz,ls=1;
	vector<long long> v;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(;1;)
	{
		for(ii=0;ii<2;ii++)
		{
			vtd.reset();
			q.push({ls,0});
			vtd[ls]=1;
			pr[ls]=ls;
			for(;!q.empty();)
			{
				k=q.front().fr;
				w=q.front().sc;
				q.pop();
				sz=al[k].size();
				for(i=0;i<sz;i++)
				{
					l=al[k][i];
					if(!vtd[l])
					{
						q.push({l,w+1});
						vtd[l]=1;
						pr[l]=k;
					}
				}
			}
			ls=k;
		}
		if(!w)
		{
			break;
		}
		printf("? %lld %lld\n",ls,pr[pr[ls]]);
		fflush(stdout);
		scanf("%lld",&k);
		v.clear();
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(l!=ls&&l!=pr[ls]&&l!=pr[pr[ls]])
			{
				v.push_back(l);
			}
		}
		al[k]=v;
		ls=k;
	}
	printf("! %lld\n",ls);
}