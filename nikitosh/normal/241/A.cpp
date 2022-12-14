#include<cstdio>
#include<algorithm>

using namespace std;

int m, k, s[10000], d[10000], max1, x[10000], y[10000], l;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &m, &k);              
	for (int i = 1; i <= m; i++)
		scanf("%d", &d[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &s[i]);   
	x[0] = 0;
	y[0] = s[1];
	for (int i = 1; i <= m; i++)
	{
		if (y[i - 1] >= d[i])
		{
			x[i] = x[i - 1] + d[i];
			y[i] = y[i - 1] - d[i] + s[i + 1];
		}
		else
		{
			max1 = (int) -1e9;
			l = d[i] - y[i - 1];
			for (int j = 1; j <= i; j++)
			{
				if (max1 < s[j])
					max1 = s[j];
			}
			if (l % max1 == 0)
			{
				y[i] = s[i + 1];
				x[i] = x[i - 1] + d[i] + (l / max1) * k;
			}
			else
			{
				y[i] = (l / max1 + 1) * max1 - l + s[i + 1];                
				x[i] = x[i - 1] + d[i] + (l / max1 + 1) * k;
			}
		}
		//printf("%d %d %d %d\n", x[i], y[i], l, max1);
	}
	printf("%d\n", x[m]);
	return 0;
}