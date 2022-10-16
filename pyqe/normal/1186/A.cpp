#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,c;
	
	scanf("%lld%lld%lld",&a,&b,&c);
	if(a<=min(b,c))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}