#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,j,sz,n,k,b=0,c;
	vector<long long> sv[100069];
	map<long long,long long> m;
	
	for(i=2;i<=100000;i++)
	{
		sz=sv[i].size();
		if(sz==0)
		{
			for(j=i;j<=100000;j+=i)
			{
				sv[j].push_back(i);
			}
			sz++;
		}
	}
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		sz=sv[k].size();
		for(j=0;j<sz;j++)
		{
			m[sv[k][j]]++;
			c=m[sv[k][j]];
			if(c>b)
			{
				b=c;
			}
		}
	}
	printf("%lld\n",max((long long)1,b));
}