#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,sz=0;
vector<pair<long long,long long>> v;

int main()
{
	long long i,z,mn=1e18,c,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=2;i*i<=m;i++)
	{
		if(m%i==0)
		{
			for(c=0;m%i==0;m/=i,c++);
			v.push_back({i,c});
			sz++;
		}
	}
	if(m>1)
	{
		v.push_back({m,1});
		sz++;
	}
	for(i=0;i<sz;i++)
	{
		z=0;
		for(k=n;k>0;k/=v[i].fr,z+=k);
		z/=v[i].sc;
		mn=min(mn,z);
	}
	printf("%lld\n",mn);
}