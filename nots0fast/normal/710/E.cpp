#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long int lli;
long long int kele (long long int pox, long long int x, long long int y)
{
	long long int cavab;
		if(pox==1)
		{
			return x;
		}
	if((pox%2))
	{
		long long int bir = kele(pox+1,x,y);
		long long int iki = kele(pox-1,x,y);
		cavab=x;
		if(bir<iki)
		{
			cavab+=bir;
		}
		else
		{
			cavab+=iki;
		}
	}
	else
	{
		if((pox/2)*x > y)
		{
			cavab = y + kele(pox/2,x,y);
		}
		else
		{
			cavab = pox*x;
		}
	}
	return cavab;
	
}
int main()
{
	 long long int n,x,y;
	 cin>>n>>x>>y;
	 cout<<kele(n,x,y);
}