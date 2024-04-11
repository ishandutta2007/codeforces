#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		if(m>(n+1)/2)
		{
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%c",".R"[i==j&&i%2&&i<=m*2]);
			}
			printf("\n");
		}
	}
}