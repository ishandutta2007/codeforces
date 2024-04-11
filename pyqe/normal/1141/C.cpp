#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];
map<long long,bool> vtd;

int main()
{
	long long i,k,mn=1e18,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		if(i-1)
		{
			scanf("%lld",&k);
			a[i]=a[i-1]+k;
		}
		if(vtd[a[i]])
		{
			printf("-1\n");
			return 0;
		}
		vtd[a[i]]=1;
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	if(mx-mn>n-1)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		a[i]+=1-mn;
		printf("%lld%c",a[i]," \n"[i==n]);
	}
}