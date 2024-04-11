#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&n,&d);
	if(d>n||(d==1&&n>1))
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(i<=n-d+2)
		{
			k=!(i%2);
		}
		else
		{
			k=i-n+d-1;
		}
		printf("%c",(char)k+'a');
	}
	printf("\n");
}