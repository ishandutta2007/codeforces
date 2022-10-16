#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i,j,sy=0,sx=0,c=0;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&ch);
			if(ch=='B')
			{
				sy+=i;
				sx+=j;
				c++;
			}
		}
	}
	printf("%lld %lld\n",sy/c,sx/c);
}