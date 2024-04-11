#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		if(k%2)
		{
			printf("7");
			k-=3;
		}
		for(i=0;i<k/2;i++)
		{
			printf("1");
		}
		printf("\n");
	}
}