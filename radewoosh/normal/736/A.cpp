#include <bits/stdc++.h>
using namespace std;

long long n;

long long a, b;
int licz;

int main()
{
	scanf("%lld", &n);
	a=1;
	b=1;
	while(1)
	{
		if (b>n)
		{
			printf("%d\n", licz-1);
			break;
		}
		swap(a, b);
		b+=a;
		licz++;
	}
	return 0;
}