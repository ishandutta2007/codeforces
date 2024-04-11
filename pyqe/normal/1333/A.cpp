#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				k=(i+j)%2-(n*m%2==0&&i==1&&j==2);
				printf("%c","BW"[k]);
			}
			printf("\n");
		}
	}
}