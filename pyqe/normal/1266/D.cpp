#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,io[100069],zs=0;
stack<pair<long long,long long>> sk;
vector<pair<pair<long long,long long>,long long>> sq;

int main()
{
	long long i,k,l,w;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		io[k]-=w;
		io[l]+=w;
	}
	for(i=1;i<=n;i++)
	{
		if(io[i]<0)
		{
			sk.push({i,-io[i]});
		}
	}
	for(i=1;i<=n;i++)
	{
		if(io[i]>0)
		{
			for(;!sk.empty()&&io[i];)
			{
				k=sk.top().fr;
				w=sk.top().sc;
				sq.push_back({{k,i},min(io[i],w)});
				zs++;
				sk.top().sc-=min(io[i],w);
				io[i]-=min(io[i],w);
				if(sk.top().sc==0)
				{
					sk.pop();
				}
			}
		}
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld %lld %lld\n",sq[i].fr.fr,sq[i].fr.sc,sq[i].sc);
	}
}