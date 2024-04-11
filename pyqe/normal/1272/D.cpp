#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ls[200069];

int main()
{
	long long i,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(i==1||a[i]<=a[i-1])
		{
			ls[i]=i;
		}
		else
		{
			ls[i]=ls[i-1];
		}
		mx=max(mx,i-ls[i]+1);
		if(ls[i]>2&&a[ls[i]]>a[ls[i]-2])
		{
			mx=max(mx,i-ls[i]+1+ls[i]-2-ls[ls[i]-2]+1);
		}
		if(ls[i]>1&&i>=ls[i]+1&&a[ls[i]+1]>a[ls[i]-1])
		{
			mx=max(mx,i-ls[i]+ls[i]-1-ls[ls[i]-1]+1);
		}
	}
	printf("%lld\n",mx);
}