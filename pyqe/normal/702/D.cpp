#include <bits/stdc++.h>

using namespace std;

long long ln,n,d1,d2,m;

int main()
{
	long long i;
	
	scanf("%lld%lld%lld%lld%lld",&ln,&n,&d1,&d2,&m);
	printf("%lld\n",min(min(d2*ln,d1*min(n,ln)+d2*(ln-min(n,ln))),min(d1*((ln-1)/n*n)+m*max((ln-1)/n-1,0ll)+d2*((ln-1)%n+1),d1*ln+m*((ln-1)/n))));
}