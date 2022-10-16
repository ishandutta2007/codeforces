#include <bits/stdc++.h>

using namespace std;

long long n,a[7];

int main()
{
	long long i,j,mx=0;
	bool bad;
	
	scanf("%lld",&n);
	for(i=0;n;n/=10,i++)
	{
		a[i]=n%10;
		mx=max(mx,a[i]);
	}
	printf("%lld\n",mx);
	for(i=1;i<=mx;i++)
	{
		bad=0;
		for(j=6;j+1;j--)
		{
			if(a[j]>=i)
			{
				bad=1;
			}
			if(bad)
			{
				printf("%lld",(long long)(a[j]>=i));
			}
		}
		printf("%c"," \n"[i==mx]);
	}
}