#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'a';
		}
		if(a[1]==a[2])
		{
			z=1;
		}
		else
		{
			for(i=1;i<n&&a[i]>=a[i+1];i++);
			z=i;
		}
		for(i=1;i<=z;i++)
		{
			printf("%c",(char)(a[i]+'a'));
		}
		for(i=z;i;i--)
		{
			printf("%c",(char)(a[i]+'a'));
		}
		printf("\n");
	}
}