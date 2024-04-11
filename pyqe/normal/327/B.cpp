#include <bits/stdc++.h>

using namespace std;

long long n,ma=1e7;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",ma-n+i," \n"[i==n]);
	}
}