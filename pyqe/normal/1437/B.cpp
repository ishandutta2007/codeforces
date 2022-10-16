#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,l,c;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			c+=!i||k==l;
			l=k;
		}
		printf("%lld\n",c/2);
	}
}