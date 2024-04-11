#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,c=0;
	char ch;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		c+=ch=='8';
	}
	printf("%lld\n",min(n/11,c));
}