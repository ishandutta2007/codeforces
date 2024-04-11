#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,j,e1,e2;
	double k,z,b=1e9;
	
	scanf("%lf",&k);
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		{
			z=abs(k-(double)i/2*j/(sqrt((double)i*i/4+j*j)));
			if(z<b)
			{
				b=z;
				e1=i;
				e2=j;
			}
		}
	}
	printf("%lld %lld\n",e1,e2);
}