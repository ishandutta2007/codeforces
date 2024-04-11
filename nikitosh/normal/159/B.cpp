#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, i, j, k, l, a[1002][1002], b[1002][1002], c[1002], d[1002], x = 0, z = 0;

int main()
{
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &k, &l);	
		a[k][l]++;
		c[l]++;
	}
	for (j = 0; j < m; j++)
	{
		scanf("%d%d", &k, &l);
		b[k][l]++;
		d[l]++;
	}
	for (i = 0; i < 1002; i++)
		x += min(c[i], d[i]);
	for (i = 0; i < 1002; i++)
		for (j = 0; j < 1002; j++)
			z += min(a[i][j], b[i][j]);
	printf("%d %d", x, z);
	return 0;
}