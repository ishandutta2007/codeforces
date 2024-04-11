#include <bits/stdc++.h>

using namespace std;

long long n,lb,rb,a[100069];

int main()
{
	long long i,j;
	
	scanf("%lld%lld%lld",&n,&lb,&rb);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=max(i-lb,1ll);j<=min(i+rb,n);j++)
		{
			if(a[j]<a[i])
			{
				j=-1;
				break;
			}
		}
		if(j!=-1)
		{
			printf("%lld\n",i);
			break;
		}
	}
}