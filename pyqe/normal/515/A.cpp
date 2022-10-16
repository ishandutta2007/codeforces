#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,s;
	
	scanf("%lld%lld%lld",&a,&b,&s);
	a=abs(a);
	b=abs(b);
	if(s>=a+b&&s%2==(a+b)%2)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}