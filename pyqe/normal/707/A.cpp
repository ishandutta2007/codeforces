#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,i,j;
	char k;
	bool g=false;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf(" %c",&k);
			if(k=='C'||k=='Y'||k=='M')
			{
				g=true;
			}
		}
	}
	if(g)
	{
		printf("#Color\n");
	}
	else
	{
		printf("#Black&White\n");
	}
}