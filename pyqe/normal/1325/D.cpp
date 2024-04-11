#include <bits/stdc++.h>

using namespace std;

long long xr,sm,df,sq[3],zs;

int main()
{
	long long i;
	
	scanf("%lld%lld",&xr,&sm);
	df=sm-xr;
	if(df<0||df%2)
	{
		zs=-1;
	}
	else if(!df)
	{
		if(!xr)
		{
			zs=0;
		}
		else
		{
			zs=1;
			sq[0]=xr;
		}
	}
	else
	{
		df/=2;
		if((xr^df)==(xr|df))
		{
			zs=2;
			sq[0]=xr|df;
			sq[1]=df;
		}
		else
		{
			zs=3;
			sq[0]=xr;
			sq[1]=df;
			sq[2]=df;
		}
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs-1]);
	}
}