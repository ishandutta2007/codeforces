#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069],sz[2],m[2];

int main()
{
	long long i,k,ii,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		a[k%2][sz[k%2]]=k;
		sz[k%2]++;
		z+=k;
	}
	for(ii=0;ii<2;ii++)
	{
		sort(a[ii],a[ii]+sz[ii],greater<long long>());
		m[ii]=min(sz[ii],min(sz[0],sz[1])+1);
		for(i=0;i<m[ii];i++)
		{
			z-=a[ii][i];
		}
	}
	printf("%lld\n",z);
}