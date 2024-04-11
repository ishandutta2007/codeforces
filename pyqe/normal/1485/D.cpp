#include <bits/stdc++.h>

using namespace std;

long long n,m,lm=720720;

int main()
{
	long long i,j,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			printf("%lld%c",lm+k*k*k*k*((i+j)%2)," \n"[j==m]);
		}
	}
}