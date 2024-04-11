#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long p[2],n,i,z[2]={0,0};
	bool g=0;
	
	scanf("%lld",&n);
	long long a[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	p[0]=0;
	p[1]=n-1;
	while(p[0]<=p[1])
	{
		if(a[p[0]]<a[p[1]])
		{
			z[g]+=a[p[1]];
			p[1]--;
		}
		else
		{
			z[g]+=a[p[0]];
			p[0]++;
		}
		g=!g;
	}
	printf("%lld %lld\n",z[0],z[1]);
}