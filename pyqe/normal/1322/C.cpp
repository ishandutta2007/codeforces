#include <bits/stdc++.h>

using namespace std;

long long n,m,a[500069];
vector<long long> al[500069];
map<vector<long long>,long long> sm;

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			al[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[l].push_back(k);
		}
		sm.clear();
		z=0;
		for(i=1;i<=n;i++)
		{
			sort(al[i].begin(),al[i].end());
			sm[al[i]]+=a[i];
		}
		for(i=1;i<=n;i++)
		{
			if(!al[i].empty())
			{
				z=__gcd(z,sm[al[i]]);
			}
		}
		printf("%lld\n",z);
	}
}