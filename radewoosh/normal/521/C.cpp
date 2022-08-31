#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n, k;
string slo;
int tab[1000007];
long long mod=1000000007;

long long razyile[1000007];
long long pot[1000007];
long long sum;
long long wyn;

long long sil[1000007];
long long odw[1000007];

long long licz(long long a)
{
	long long x=mod-2;
	long long ret=1;
	while(x)
	{
		if (x&1)
		{
			ret*=a;
			ret%=mod;
		}
		a*=a;
		a%=mod;
		x>>=1;
	}
	return ret;
}

long long ilepo(int a, int b)
{
	if (b>a)
	return 0;
	return (sil[a]*((odw[b]*odw[a-b])%mod))%mod;
}

int main()
{
	cin >> n >> k;
	cin >> slo;
	sil[0]=1;
	odw[0]=1;
	pot[0]=1;
	for (int i=1; i<=n; i++)
	{
		pot[i]=(pot[i-1]*10)%mod;
		sil[i]=(sil[i-1]*i)%mod;
		odw[i]=licz(sil[i]);
		tab[i]=slo[i-1]-'0';
	}
	for (int i=n; i; i--)
	{
		razyile[n-i]=ilepo(i-1, k);
		sum+=razyile[n-i]*pot[n-i];
		if (i!=n)
		{
			sum-=razyile[n-1-i]*pot[n-1-i];
			razyile[n-1-i]=ilepo(i-1, k-1);
			sum+=razyile[n-1-i]*pot[n-1-i];
		}
		sum%=mod;
		sum+=mod;
		sum%=mod;
		wyn+=sum*tab[i];
		wyn%=mod;
	}
	printf("%lld\n", wyn);
	return 0;
}