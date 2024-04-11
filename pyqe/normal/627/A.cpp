#include <bits/stdc++.h>

using namespace std;

long long sm,xr,ad;

int main()
{
	long long z;
	
	scanf("%lld%lld",&sm,&xr);
	ad=sm-xr;
	if(ad<0||ad%2!=0)
	{
		printf("0\n");
		return 0;
	}
	ad/=2;
	if(xr+ad!=(xr|ad))
	{
		printf("0\n");
		return 0;
	}
	z=(1ll<<__builtin_popcountll(xr))-!ad*2;
	printf("%lld\n",z);
}