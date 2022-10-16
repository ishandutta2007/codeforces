#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sq[100069],zs;

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
			a[i]=ch-'0';
		}
		zs=0;
		for(i=n;i;i--)
		{
			if(a[i])
			{
				zs++;
				sq[zs]=a[i]-1;
			}
			else
			{
				zs++;
				sq[zs]=a[i-1]+a[i-2]*10-1;
				i-=2;
			}
		}
		for(i=zs;i;i--)
		{
			printf("%c",(char)(sq[i]+'a'));
		}
		printf("\n");
	}
}