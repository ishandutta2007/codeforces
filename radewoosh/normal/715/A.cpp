#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	for (long long i=1; i<=n; i++)
	{
		long long p=i*(i+1)*(i+1)-(i-1);
		if (i==1)
			p-=2;
		printf("%lld\n", p);
	}
	return 0;
}