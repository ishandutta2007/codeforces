#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long ln,n,a[100069],pr[2][100069];
multiset<pair<long long,long long>> ms[2];
bitset<100069> sq;

int main()
{
	long long i,ii,lb[2],rb[2],e,p;
	bool bad[2];
	
	scanf("%lld%lld",&n,&ln);
	for(ii=0;ii<2;ii++)
	{
		ms[ii].insert({0,0});
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld%lld",lb+ii,rb+ii);
			bad[ii]=ms[ii].empty();
		}
		for(ii=0;ii<2;ii++)
		{
			if(!bad[!ii])
			{
				ms[ii].insert({a[i-1],i-1});
			}
			for(;!ms[ii].empty()&&(a[i]>rb[ii]||a[i]<lb[ii]||ms[ii].begin()->fr<lb[!ii]);ms[ii].erase(ms[ii].begin()));
			for(;!ms[ii].empty()&&prev(ms[ii].end())->fr>rb[!ii];ms[ii].erase(prev(ms[ii].end())));
			pr[ii][i]=-1;
			if(!ms[ii].empty())
			{
				pr[ii][i]=ms[ii].begin()->sc;
			}
		}
	}
	e=pr[0][n]==-1;
	if(pr[e][n]!=-1)
	{
		printf("Yes\n");
		for(p=n;p;p=pr[e][p],e^=1)
		{
			for(i=pr[e][p]+1;i<=p;i++)
			{
				sq[i]=e;
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",(long long)sq[i]," \n"[i==n]);
		}
	}
	else
	{
		printf("No\n");
	}
}