#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long a, b, n;
long long mod=1000000007;
long long wyn;
long long sil[1000007];

bool czy(long long v)
{
	while(v)
	{
		if ((v%10)!=a && (v%10)!=b)
		return false;
		v/=10;
	}
	return true;
}

long long dziel(long long lic, long long mia)
{
	vector <long long> wek;
	long long x=mod-2;
	while(x)
	{
		wek.push_back(x%2);
		x/=2;
	}
	long long doz=1;
	x=mia;
	for (int i=0; i<wek.size(); i++)
	{
		if (wek[i])
		{
			doz*=x;
			doz%=mod;
		}
		x=(x*x)%mod;
	}
	return (doz*lic)%mod;
}

int main()
{
	scanf("%lld%lld%lld", &a, &b, &n);
	sil[0]=1;
	for (long long i=1; i<=n; i++)
	{
		sil[i]=(sil[i-1]*i)%mod;
	}
	for (long long i=0; i<=n; i++)
	{
		if (czy(i*a+(n-i)*b))
		{
			wyn+=dziel(sil[n], (sil[i]*sil[n-i])%mod);
			wyn%=mod;
		}
	}
	printf("%lld", wyn);
	return 0;
}