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
		z=0;
		for(i=(n+1)/2;i&&a[i]==a[(n+1)/2];i--,z++);
		for(i=(n+1)/2+1;i<=n&&a[i]==a[(n+1)/2];i++,z++);
		printf("%lld\n",z);
	}
}