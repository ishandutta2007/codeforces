#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr,i,y,x;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		d--;
		y=d%n;
		x=d/n;
		printf("%lld\n",y*m+x+1);
	}
}