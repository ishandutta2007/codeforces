#include <bits/stdc++.h>
using namespace std;

int n;
long long k;

long long tab[1000007];

long long bsa, bsb, bss;

int l;
int ost[10000007];
int dp[10000007];

int licz(int v)
{
	if (v<l)
		return 0;
	if (v==1)
		return 1;
	if (ost[v]!=l)
		dp[v]=max(licz((v)/2)+licz((v+1)/2), 1);
	ost[v]=l;
	return dp[v];
}

long long check(int v)
{
	long long ret=0;
	l=v;
	for (int i=1; i<=n; i++)
		ret+=licz(tab[i]);
	return ret;
}

int main()
{
	scanf("%d%lld", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	sort(tab+1, tab+1+n);
	bsa=1;
	bsb=tab[n];
	if (check(1)<k)
	{
		printf("-1\n");
		return 0;
	}
	while(bsa<bsb)
	{
		bss=(bsa+bsb+2)>>1;
		if (check(bss)>=k)
			bsa=bss;
		else
			bsb=bss-1;
	}
	printf("%lld\n", bsa);
	return 0;
}