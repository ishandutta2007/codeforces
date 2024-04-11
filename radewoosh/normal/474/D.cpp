#include <iostream>
#include <cstdio>
using namespace std;

int t, k, a, b;
long long mod=1000000007;
long long dyn[100007];
long long tab[2000007];

int main()
{
	scanf("%d%d", &t, &k);
	dyn[0]=1;
	for (int i=1; i<=100000; i++)
	{
		dyn[i]=dyn[i-1];
		if (i>=k)
		{
			dyn[i]+=dyn[i-k];
			dyn[i]%=mod;
		}
		tab[i]=(tab[i-1]+dyn[i])%mod;
	}
	for (int i=1; i<=t; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%lld\n", (((tab[b]-tab[a-1])%mod)+mod)%mod);
	}
	return 0;
}