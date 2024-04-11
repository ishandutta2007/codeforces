#include <bits/stdc++.h>

using namespace std;

long long n,ps[100069];

int main()
{
	long long i,k;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		k=ch-'0';
		if(k!=4&&k!=7)
		{
			printf("NO\n");
			return 0;
		}
		ps[i]=ps[i-1]+k;
	}
	if(ps[n/2]==ps[n]-ps[n/2])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}