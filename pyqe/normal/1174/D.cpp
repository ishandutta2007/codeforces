#include <bits/stdc++.h>

using namespace std;

long long n,d,zs;
vector<long long> sq;
bitset<1<<18> vtd;

int main()
{
	long long i,xr=0;
	
	scanf("%lld%lld",&n,&d);
	vtd[0]=1;
	vtd[d]=1;
	for(i=0,zs=0;1;zs++)
	{
		for(;i<1<<n&&vtd[i];i++);
		if(i==1<<n)
		{
			break;
		}
		sq.push_back(xr^i);
		vtd[i]=1;
		vtd[i^d]=1;
		xr=i;
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs-1]);
	}
}