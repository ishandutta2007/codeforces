#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,l=-69;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(i<n-1)
		{
			l=k;
		}
	}
	if(!k)
	{
		l=-1;
	}
	if(k==15)
	{
		l=16;
	}
	if(l==-69)
	{
		printf("-1\n");
	}
	else if(k>l)
	{
		printf("UP\n");
	}
	else
	{
		printf("DOWN\n");
	}
}