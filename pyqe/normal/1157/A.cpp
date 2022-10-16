#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,bool> vtd;

int main()
{
	long long z;
	
	scanf("%lld",&n);
	z=1;
	vtd[n]=1;
	for(;1;)
	{
		for(n++;n%10==0;n/=10);
		if(vtd[n])
		{
			break;
		}
		z++;
		vtd[n]=1;
	}
	printf("%lld\n",z);
}