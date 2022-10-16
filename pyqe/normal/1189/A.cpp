#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> a;

int main()
{
	long long i,c=0;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'0';
		c+=a[i];
	}
	printf("%lld\n",1ll+(c*2==n));
	for(i=1;i<=n;i++)
	{
		printf("%lld",(long long)a[i]);
		if(i==1&&c*2==n)
		{
			printf(" ");
		}
	}
	printf("\n");
}