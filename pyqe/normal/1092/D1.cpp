#include <bits/stdc++.h>

using namespace std;

long long n,nn=0;
bitset<200069> sk;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		k%=2;
		if(!nn||sk[nn]!=k)
		{
			nn++;
			sk[nn]=k;
		}
		else
		{
			nn--;
		}
	}
	if(nn<=1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}