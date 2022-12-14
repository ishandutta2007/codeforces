#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m, x, y, len, a[2000][10], wh[2000], bl[2000], sum[2000][10];
char s[2000], b[1002][1002];

int main()
{                                
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%d%d%d%d\n", &n, &m, &x, &y);
	for (int i = 0; i < n; i++)
	{                                            
		gets(s);
		len = strlen(s);
		for (int j = 0; j < len; j++)
			b[i][j] = s[j];                          
	}                      
	for (int i = 0; i < 2000; i++)
	{
		a[i][0] = 1e9;
		a[i][1] = 1e9;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			if (b[j][i] == '.')
				bl[i]++;
			else
				wh[i]++;
	}
	a[0][0] = wh[0];
	a[0][1] = bl[0];
	sum[0][0] = wh[0];
	sum[0][1] = bl[0];
	for (int i = 1; i < m; i++)
	{
		sum[i][0] = sum[i - 1][0] + wh[i];
		sum[i][1] = sum[i - 1][1] + bl[i];       
	}                                
	for (int i = 1; i < m; i++)
	{
		if (i <= x - 1)
		{
			a[i][0] = sum[i][0];
			a[i][1] = sum[i][1];
		}
		for (int j = i - x; j >= max(i - y, 0); j--)
		{
			if (i <= y - 1)
			{
				a[i][0] = min(a[i][0], sum[i][0]);
				a[i][1] = min(a[i][1], sum[i][1]);  
			}
			if (j >= x - 1)
			{
				a[i][0] = min(a[i][0], a[j][1] + sum[i][0] - sum[j][0]); 	
				a[i][1] = min(a[i][1], a[j][0] + sum[i][1] - sum[j][1]);
			}
		}
	}
	//for (int i = 0; i < m; i++)
//		printf("%d %d %d %d\n", sum[i][0], sum[i][1], a[i][0], a[i][1]);
	printf("%d\n", min(a[m - 1][0], a[m - 1][1]));
	return 0;
}