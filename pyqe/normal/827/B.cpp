#include <bits/stdc++.h>

using namespace std;

long long n,d,nn=0,ls[200069];

int main()
{
	long long i,p,z;
	
	scanf("%lld%lld",&n,&d);
	for(z=2;1;z++)
	{
		if(n<=z/2*d+1+z%2)
		{
			break;
		}
	}
	printf("%lld\n",z);
	nn=1;
	if(z%2)
	{
		nn++;
		printf("1 2\n");
	}
	for(i=1;i<=d;i++)
	{
		ls[i]=i%2%(z%2+1)+1;
	}
	for(p=1;nn<n;p=p%d+1)
	{
		nn++;
		printf("%lld %lld\n",ls[p],nn);
		ls[p]=nn;
	}
}