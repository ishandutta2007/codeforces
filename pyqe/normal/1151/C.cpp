#include <bits/stdc++.h>

using namespace std;

long long dv=1e9+7;

long long sm(long long x)
{
	long long i,z=0,fq[2]={0,0};
	
	for(i=0;z<x;i++)
	{
		z+=1ll<<i;
		fq[i%2]=((fq[i%2]+(1ll<<i))%dv+dv-max(z-x,0ll))%dv;
	}
	return (fq[0]*fq[0]%dv+fq[1]*(fq[1]+1)%dv)%dv;
}

int main()
{
	long long lh,rh;
	
	scanf("%lld%lld",&lh,&rh);
	printf("%lld\n",(sm(rh)+dv-sm(lh-1))%dv);
}