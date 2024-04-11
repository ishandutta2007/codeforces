#include <bits/stdc++.h>

using namespace std;

long long n,m,dv=1e9+7;

int main()
{
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",m*(m-1)/2%dv*(n*(n+1)/2%dv*m%dv+n)%dv);
}