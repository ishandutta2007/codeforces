#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%c","*D"[abs(i-(n+1)/2)+abs(j-(n+1)/2)<=n/2]);
		}
		printf("\n");
	}
}