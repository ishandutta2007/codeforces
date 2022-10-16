#include <bits/stdc++.h>

using namespace std;

long long n,m,a[8][8],pm[8],inf=1e18;

int main()
{
	long long i,j,sm,mx,mn,z=1e18;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		cin>>s;
		for(j=0;j<m;j++)
		{
			a[i][j]=s[j]-'0';
			pm[j]=j;
		}
	}
	for(;1;)
	{
		mx=-inf;
		mn=inf;
		for(i=0;i<n;i++)
		{
			sm=0;
			for(j=0;j<m;j++)
			{
				sm=sm*10+a[i][pm[j]];
			}
			mx=max(mx,sm);
			mn=min(mn,sm);
		}
		z=min(z,mx-mn);
		if(!next_permutation(pm,pm+m))
		{
			break;
		}
	}
	printf("%lld\n",z);
}