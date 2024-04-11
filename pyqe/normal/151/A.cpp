#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,k,l,c,d,p,nl,np;
	
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&n,&k,&l,&c,&d,&p,&nl,&np);
	printf("%lld\n",min(min(k*l/nl,c*d),p/np)/n);
}