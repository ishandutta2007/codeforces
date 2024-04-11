#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i,z;
	
	scanf("%lld%lld",&n,&m);
	if(n>m)
	{
		swap(n,m);
	}
	if(n==1)
	{
		z=m/6*3+max(m%6-3,0ll);
	}
	else
	{
		z=n*m/2;
		if(n==2)
		{
			if(m==3||m==7)
			{
				z--;
			}
			else if(m==2)
			{
				z-=2;
			}
		}
	}
	printf("%lld\n",z*2);
}