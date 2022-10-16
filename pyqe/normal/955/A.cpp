#include <bits/stdc++.h>

using namespace std;

long long hh,mm,n,m,co,d;

int main()
{
	long long i;
	double z;
	
	scanf("%lld%lld%lld%lld%lld%lld",&hh,&mm,&n,&m,&co,&d);
	z=(n+d-1)/d*co;
	mm+=hh*60;
	mm=max(20*60-mm,0ll);
	n+=m*mm;
	z=min(z,(double)((n+d-1)/d*co*4)/5);
	printf("%.4lf\n",z);
}