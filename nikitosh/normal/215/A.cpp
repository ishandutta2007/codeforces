#include<cstdio>

const int maxn = 1000000;

int n, m, ans, a[maxn], b[maxn], i, j, max = -1e9;

int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf("%d", &b[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (b[j] % a[i] == 0 && b[j] / a[i] > max)
				max = b[j] / a[i];

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (b[j] % a[i] == 0 && b[j] / a[i] == max)
				ans++;
 	printf("%d\n", ans);
	return 0;
}