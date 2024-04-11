#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j%2==0)
			{
				k=j*n+i+1;
			}
			else
			{
				k=j*n+n-i;
			}
			printf("%lld%c",k," \n"[j==n-1]);
		}
	}
}