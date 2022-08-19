#include <bits/stdc++.h>
using namespace std;

int n;
long long a[1000007];
long long b[1000007];

long long s;
long long tab[1000007];

long long ile[107];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &a[i]);
		s+=a[i];
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &b[i]);
		s+=b[i];
	}
	s/=n;
	s/=2;
	for (int i=1; i<=n; i++)
	{
		tab[i]=(a[i]+b[i]-s)/n;
		for (int j=0; j<50; j++)
		{
			long long jed=1;
			if (tab[i]&(jed<<j))
				ile[j]++;
		}
	}
	for (int i=1; i<=n; i++)
	{
		long long aa=0;
		long long bb=0;
		for (int j=0; j<50; j++)
		{
			long long jed=1;
			
			if (tab[i]&(jed<<j))
				aa+=(jed<<j)*ile[j];
			else
				aa+=(jed<<j)*0;
				
			if (tab[i]&(jed<<j))
				bb+=(jed<<j)*n;
			else
				bb+=(jed<<j)*ile[j];
		}
		if (aa!=a[i] || bb!=b[i])
		{
			printf("-1\n");
			return 0;
		}
	}
	for (int i=1; i<=n; i++)
		printf("%lld ", tab[i]);
	printf("\n");
	return 0;
}