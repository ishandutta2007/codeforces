#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[100069];

int main()
{
	long long i,w;
	
	scanf("%lld%lld",&n,&d);
	if(n==1)
	{
		if(!d)
		{
			printf("69\n");
		}
		else
		{
			printf("-1\n");
		}
		return 0;
	}
	if(n/2>d)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		sq[i]=i;
	}
	w=d-n/2+1;
	sq[n/2*2-1]=(n+w-1)/w*w;
	sq[n/2*2]=sq[n/2*2-1]+w;
	if(n%2)
	{
		sq[n]=1e9;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}