#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long sm,xr,ad;
	
	scanf("%llu%llu",&sm,&xr);
	if(sm<xr||(sm-xr)%2==1)
	{
		printf("-1\n");
		return 0;
	}
	ad=(sm-xr)/2;
	if((xr^ad)!=xr+ad)
	{
		printf("-1\n");
		return 0;
	}
	printf("%llu %llu\n",ad,ad+xr);
}