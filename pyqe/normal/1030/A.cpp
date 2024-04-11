#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,k;
	bool g=false;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k==1)
		{
			g=true;
		}
	}
	if(g)
	{
		printf("HARD\n");
	}
	else
	{
		printf("EASY\n");
	}
}