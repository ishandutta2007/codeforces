#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int n;

int mod(int a)
{
	if (a < 0)
		return (a + 2 * n) % n;
	else
		return a % n;
}

int ans[1000100];

int main()
{
	int q;
	scanf("%d%d", &n, &q);
	int a, b;
	a = 0, b = 1;
	for (int i = 0; i < q; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int x;
			scanf("%d", &x);
			a = mod(a + x);
			b = mod(b + x);
		}
		else
		{
			if (a % 2 == 0)
				a++, b--;
			else
				a--, b++;
		}
	}
	for (int i = 0; i < n / 2; i++)
	{
		ans[mod(a + i * 2)] = 1 + i * 2;
		ans[mod(b + i * 2)] = 2 + i * 2;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
}