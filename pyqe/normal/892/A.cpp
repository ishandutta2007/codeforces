#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j,r,k,sm=0,mx[2]={0,0};
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		sm+=k;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(j=0;j<2;j++)
		{
			if(k>mx[j])
			{
				for(r=1;r>j;r--)
				{
					mx[r]=mx[r-1];
				}
				mx[j]=k;
				break;
			}
		}
	}
	if(sm<=mx[0]+mx[1])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}