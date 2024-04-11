#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j;
	double k,l=0,ml=0,mll=0,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&k);
		mll=(mll+ml*2)*k+k*(1.0-l);
		ml=(ml+1-l)*k;
		z+=mll;
		l=k;
	}
	printf("%.15lf\n",z);
}