#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,j,r,k,z;
	vector<long long> v[4];
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		v[k].push_back(i);
	}
	z=min(min(v[1].size(),v[2].size()),v[3].size());
	printf("%lld\n",z);
	for(i=0;i<z;i++)
	{
		printf("%lld %lld %lld\n",v[1][i],v[2][i],v[3][i]);
	}
}