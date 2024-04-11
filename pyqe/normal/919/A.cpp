#include <bits/stdc++.h>

using namespace std;

long long n,m,inf=1e18;

int main()
{
	long long i,k,l;
	double mn=inf;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		mn=min(mn,(double)k/l);
	}
	printf("%.8lf\n",mn*m);
}