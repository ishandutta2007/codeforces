#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long i,j,k;
	
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",(n-1)*2+(m-1)*(n+1)+1);
	for(i=0;i<n-1;i++)
	{
		printf("U");
	}
	for(i=0;i<m-1;i++)
	{
		printf("L");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m-1;j++)
		{
			printf("%c","RL"[i%2]);
		}
		printf("D");
	}
	printf("\n");
}