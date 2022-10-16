#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	for(i=0;i<=n+n;i++)
	{
		for(j=0;j<=n+n;j++)
		{
			k=n-abs(i-n)-abs(j-n);
			if(k<0)
			{
				printf(" ");
			}
			else
			{
				printf("%lld",k);
			}
			if(k==0&&j>=n)
			{
				printf("\n");
				break;
			}
			printf(" ");
		}
	}
}