#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		if(n>m)
		{
			swap(n,m);
		}
		if(n==1||m==2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}