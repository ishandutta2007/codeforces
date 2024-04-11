#include<cstdio>
#include<algorithm>

using namespace std;

int n, a[100];

int main()
{
	scanf("%d", &n);
	if (n == 1 || n == 2)
	{
		printf("%d\n", -1);
		return 0;
	}
	for (int i = 1; i <= n; i++)
		a[i] = n - i + 1;
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}