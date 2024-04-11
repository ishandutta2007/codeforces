#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(c=0,i=1;c<n;i++)
		{
			c+=i%3&&i%10!=3;
		}
		i--;
		printf("%lld\n",i);
	}
}