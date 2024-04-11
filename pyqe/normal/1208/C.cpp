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
			printf("%lld%c",(i/2*n/2+j/2)*4+(i*2+j)%4," \n"[j==n-1]);
		}
	}
}