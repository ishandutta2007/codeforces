#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,j,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				z=(i+j)%2^((i-1)/2+(j-1)/2)%2;
				printf("%lld%c",z," \n"[j==m]);
			}
		}
	}
}