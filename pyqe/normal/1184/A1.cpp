#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	n--;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			k=n/i-i-1;
			if(k<=0||k%2==1)
			{
				continue;
			}
			k/=2;
			printf("%lld %lld\n",i,k);
			return 0;
		}
	}
	printf("NO\n");
}