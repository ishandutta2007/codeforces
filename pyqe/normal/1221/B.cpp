#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((i+j)%2==0)
			{
				printf("B");
			}
			else
			{
				printf("W");
			}
		}
		printf("\n");
	}
}