#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,zs[2];
vector<pair<long long,long long>> sq[2];

int main()
{
	long long i,k,l,p,e;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		p=k<l;
		if(k<l)
		{
			k=-k;
			l=-l;
		}
		if(k!=l)
		{
			sq[p].push_back({k,i});
			zs[p]++;
		}
	}
	e=zs[1]>zs[0];
	sort(sq[e].begin(),sq[e].end());
	printf("%lld\n",zs[e]);
	for(i=0;i<zs[e];i++)
	{
		printf("%lld%c",sq[e][i].sc," \n"[i==zs[e]-1]);
	}
}