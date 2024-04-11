#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,j,k,e;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		e=-1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				if(ch!='.')
				{
					k=ch=='W'^(i+j)%2;
					if(e==-1||e==k)
					{
						e=k;
					}
					else
					{
						e=-2;
					}
				}
			}
		}
		if(e!=-2)
		{
			printf("YES\n");
			e=max(e,0ll);
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					printf("%c","RW"[(i+j)%2^e]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("NO\n");
		}
	}
}