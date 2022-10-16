#include <bits/stdc++.h>

using namespace std;

long long n,lh,rh;

int main()
{
	scanf("%lld%lld%lld",&n,&lh,&rh);
	printf("%lld %lld\n",n-lh+(1<<lh)-1,(1<<rh)-1+(n-rh)*(1<<rh-1));
}