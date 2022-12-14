#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, a[1005][1005], max1, max2, l, ans = -1;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int max1 = max2 = 0;
			for (int g = 0; g < m; g++)
				if (a[i][g] > ans && a[j][g] > ans)
				{
					l = min(a[i][g], a[j][g]);
					if (l >= max1)
					{
						max2 = max1;
						max1 = l;
					}
					else if (l > max2)
						max2 = l;
				}
			ans = max(ans, max2);
		}
	printf("%d\n", ans);			
}