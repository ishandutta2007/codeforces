#include <bits/stdc++.h>

using namespace std;

long long n,pr[100069],dg[100069];
bitset<100069> cd;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%lld",pr+i);
		cd[pr[i]]=1;
	}
	for(i=2;i<=n;i++)
	{
		dg[pr[i]]+=!cd[i];
	}
	for(i=1;i<=n;i++)
	{
		if(cd[i]&&dg[i]<3)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}