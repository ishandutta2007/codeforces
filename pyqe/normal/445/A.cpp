#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i,j;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf(" %c",&ch);
			if(ch=='.')
			{
				ch="WB"[(i+j)%2];
			}
			printf("%c",ch);
		}
		printf("\n");
	}
}