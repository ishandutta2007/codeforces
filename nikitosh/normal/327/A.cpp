#include<cstdio>
#include<algorithm>

using namespace std;

int n, a[105], ans = -1, sum[105], s, l;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (i != 0)
			sum[i] = sum[i - 1];
		sum[i] += a[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			l = sum[j];
			if (i != 0)
				l -= sum[i - 1];
			ans = max(ans, sum[n - 1] - 2 * l + j - i + 1);
		}
	printf("%d\n", ans);
	return 0;
}