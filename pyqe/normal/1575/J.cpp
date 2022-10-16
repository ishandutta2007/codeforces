#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d;
multiset<pair<long long,bool>> ms[1069];

int main()
{
	long long i,j,u,k,y,x;
	multiset<pair<long long,bool>>::iterator it;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			if(k!=2)
			{
				ms[j].insert({i,k==3});
			}
		}
	}
	for(i=1;i<=d;i++)
	{
		scanf("%lld",&x);
		y=1;
		for(;1;)
		{
			it=ms[x].lower_bound({y,0});
			if(it==ms[x].end())
			{
				break;
			}
			y=it->fr;
			u=!(it->sc)*2-1;
			ms[x].erase(it);
			x+=u;
		}
		printf("%lld%c",x," \n"[i==d]);
	}
}