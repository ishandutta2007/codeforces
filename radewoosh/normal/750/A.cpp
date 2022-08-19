#include <bits/stdc++.h>
using namespace std;

int n, k;

int aktu;

int wyn;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		if (aktu+i*5+k<=240)
		{
			wyn++;
			aktu+=i*5;
		}
	}
	printf("%d\n", wyn);
	return 0;
}