#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],mn=1e15,mx=-1;

int main()
{
	long long i,c=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>mn&&a[i]<mx)
		{
			c++;
		}
	}
	printf("%lld\n",c);
}