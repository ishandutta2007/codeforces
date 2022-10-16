#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		for(i=0;i<k;i++)
		{
			printf("%c",(char)(i%3+'a'));
		}
		printf("\n");
	}
}