#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<n;i++)
		{
			printf("%c",(char)(i%d+'a'));
		}
		printf("\n");
	}
}