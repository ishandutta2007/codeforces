#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];
bitset<200069> vtd;

int main()
{
	long long i,ii,u,p[2];
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(vtd[a[i]])
		{
			printf("NO\n");
			return 0;
		}
		vtd[a[i]]=1;
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(p[ii]=(n+1)*ii;p[ii]!=n-(n-1)*ii&&a[p[ii]+u]>a[p[ii]];p[ii]+=u);
	}
	if(p[0]>=p[1])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}