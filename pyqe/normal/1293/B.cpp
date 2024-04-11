#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	double z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		z+=(double)1/i;
	}
	printf("%.12lf\n",z);
}