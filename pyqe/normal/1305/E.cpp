#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[5069],inf=1e9;

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		if(!d)
		{
			sq[i]=inf-(n-i)*100000;
		}
		else
		{
			k=min((i-1)/2,d);
			sq[i]=i+((i-1)/2-k)*2;
			d-=k;
		}
	}
	if(d)
	{
		printf("-1\n");
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}