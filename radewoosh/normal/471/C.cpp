#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long n;
int wyn;

int main()
{
	scanf("%lld", &n);
	for (long long i=1; i*i<=n; i++)
	{
		if (n-i*2>=0 && !((n-i*2)%3) && ((n-i*2)/3)>=(((i-1)*(i-1)-(i-1))/2)+(i-1))
		wyn++;
	}
	printf("%d", wyn);
	return 0;
}