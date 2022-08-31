#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
int k;
int a, b;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=k; i++)
	{
		scanf("%d%d", &a, &b);
		if (n-a<=4 || a<=5 || m-b<=4 || b<=5)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}