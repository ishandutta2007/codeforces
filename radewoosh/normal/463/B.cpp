#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, s;
int wyn;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &s);
		wyn=max(wyn, s);
	}
	printf("%d", wyn);
	return 0;
}