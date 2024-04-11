#include <bits/stdc++.h>

using namespace std;

inline long long qr(long long x,long long y)
{
	long long k;
	
	printf("? %lld %lld\n",x,y);
	fflush(stdout);
	scanf("%lld",&k);
	return k;
}

int main()
{
	long long i,k,l,z;
	
	for(i=2;1;i++)
	{
		k=qr(1,i);
		if(k==-1)
		{
			break;
		}
		l=qr(i,1);
		if(k!=l)
		{
			z=k+l;
			break;
		}
		z=i;
	}
	printf("! %lld\n",z);
	fflush(stdout);
}