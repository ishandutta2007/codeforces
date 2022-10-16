#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i,z;
	
	scanf("%lld%lld",&n,&m);
	for(z=n+1;1;z++)
	{
		for(i=2;i*i<=z;i++)
		{
			if(z%i==0)
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			break;
		}
	}
	if(z==m)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}