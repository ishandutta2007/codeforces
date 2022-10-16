#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j,k,e,y[2]={1,1},x[2]={1,2};
	
	scanf("%lld",&n);
	for(i=0;i<n*n;i++)
	{
		scanf("%lld",&k);
		e=k==1;
		if(y[e]<=n)
		{
			printf("%lld %lld %lld\n",e+1,y[e],x[e]);
		}
		else
		{
			for(j=1;j==e+1||j==k;j++);
			printf("%lld %lld %lld\n",j,y[!e],x[!e]);
			e^=1;
		}
		fflush(stdout);
		x[e]+=2;
		if(x[e]>n)
		{
			y[e]++;
			x[e]=1+(y[e]%2==e);
		}
	}
}