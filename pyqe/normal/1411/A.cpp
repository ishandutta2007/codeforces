#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> a;

int main()
{
	long long t,rr,i;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch==')';
		}
		for(i=n;i&&a[i];i--);
		if(n-i>i)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}