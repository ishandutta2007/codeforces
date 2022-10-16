#include <bits/stdc++.h>

using namespace std;

const long long ln=86400;
long long n,d;

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		d-=ln-k;
		if(d<=0)
		{
			break;
		}
	}
	printf("%lld\n",i);
}