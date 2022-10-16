#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n*2;j++)
			{
				k=max(n+1-j,j-n);
				printf("%c","()"[j>n^(k<=i-1&&k%2==(i-1)%2)]);
			}
			printf("\n");
		}
	}
}