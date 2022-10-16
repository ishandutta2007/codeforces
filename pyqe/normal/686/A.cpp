#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long z,c=0,n,i,k;
	char ch;
	
	scanf("%lld%lld",&n,&z);
	for(i=0;i<n;i++)
	{
		scanf(" %c%lld",&ch,&k);
		if(ch=='+')
		{
			z+=k;
		}
		else if(ch=='-')
		{
			if(z>=k)
			{
				z-=k;
			}
			else
			{
				c++;
			}
		}
	}
	printf("%lld %lld\n",z,c);
}