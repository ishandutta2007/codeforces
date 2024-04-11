#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,c,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(c=0,k=n;k>1;k/=2,c++);
		printf("%lld\n",c);
		n-=c+1;
		sm=1;
		for(i=1;i<=c;i++)
		{
			k=min(n/(c+1-i),sm);
			printf("%lld%c",k," \n"[i==c]);
			n-=k*(c+1-i);
			sm+=k;
		}
	}
}