#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=16;i+1;i--)
	{
		if(n>>i&1)
		{
			n^=1ll<<i;
			printf("%lld%c",i+1," \n"[!n]);
		}
	}
}