#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,sm=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;1;i++)
	{
		sm+=i;
		if(sm>=d&&i+sm-d==n)
		{
			printf("%lld\n",sm-d);
			break;
		}
	}
}