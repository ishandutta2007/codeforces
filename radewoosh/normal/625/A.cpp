#include <bits/stdc++.h>
using namespace std;

long long n, a, b, c;

long long wyn;

int main()
{
	scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
	if (b-c<a)
	{
		wyn=(n-c)/(b-c);
		wyn=max(wyn, (long long)0);
		n-=wyn*(b-c);
	}
	wyn+=n/a;
	printf("%lld\n", wyn);
	return 0;
}