#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	if(n%2)
	{
		printf("-1\n");
		return 0;
	}
	for(i=n;i;i--)
	{
		printf("%lld%c",i," \n"[i==1]);
	}
}