#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,sm=0,mn=0;
	char ch;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		sm+=(ch=='+')*2-1;
		mn=min(mn,sm);
	}
	printf("%lld\n",-mn+sm);
}