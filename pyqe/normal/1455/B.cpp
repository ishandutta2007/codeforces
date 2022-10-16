#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;(i+1)*(i+2)/2<=n;i++);
		k=i*(i+1)/2;
		printf("%lld\n",i+(n>k)+(n-k==i));
	}
}