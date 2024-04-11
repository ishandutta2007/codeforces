#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&k,&l);
		printf("%lld\n",max(max(k*m,l*n),max((n-1-k)*m,(m-1-l)*n)));
	}
}