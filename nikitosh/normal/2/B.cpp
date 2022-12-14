#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N, k, a1[1005][1005], a2[1005][1005], d1[1005][1005], d2[1005][1005], l, boo, m1;
vector <char> ans;

int main()
{    
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	//printf("AAA");
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &k);
			if (k == 0)
			{
				boo = 1;
				m1 = i;
				continue;
			}
			while (k % 2 == 0)
			{
				a1[i][j]++;
				k /= 2;
			}
			while (k % 5 == 0)
			{
				a2[i][j]++;
				k /= 5;
			}
		}
	//printf("AAA");
	d1[0][0] = a1[0][0];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (i == 0)
				d1[i][j] = d1[i][j - 1] + a1[i][j];
			if (j == 0)
				d1[i][j] = d1[i - 1][j] + a1[i][j];
			if (i != 0 && j != 0)
			{
				if (d1[i - 1][j] < d1[i][j - 1])
					d1[i][j] = d1[i - 1][j] + a1[i][j];
				else			
					d1[i][j] = d1[i][j - 1] + a1[i][j];
			}
		}
	d2[0][0] = a2[0][0];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (i == 0)
				d2[i][j] = d2[i][j - 1] + a2[i][j];
			if (j == 0)
				d2[i][j] = d2[i - 1][j] + a2[i][j];
			if (i != 0 && j != 0)
			{
				if (d2[i - 1][j] < d2[i][j - 1])
					d2[i][j] = d2[i - 1][j] + a2[i][j];
				else			
					d2[i][j] = d2[i][j - 1] + a2[i][j];
			}
		}
   	if (min(d1[N - 1][N - 1], d2[N - 1][N - 1]) != 0 && boo == 1)
   	{
		printf("1\n");
		for (int i = 0; i < m1; i++)
			printf("D");
		for (int i = 0; i < N - 1; i++)
			printf("R");	
		for (int i = 0; i < N - 1 - m1; i++)
			printf("D");
   		return 0;
   	}
	printf("%d\n", min(d1[N - 1][N - 1], d2[N - 1][N - 1]));
	if (d1[N - 1][N - 1] < d2[N - 1][N - 1])
	{
		k = N - 1;
		l = N - 1;
		while (k != 0 || l != 0)
		{
			if (k == 0)
			{
				ans.push_back('R');
				l--;
				continue;
			}
			if (l == 0)
			{
				ans.push_back('D');
				k--;
				continue;
			}
			if (k != 0 && l != 0)
			{
				if (d1[k - 1][l] < d1[k][l - 1])
				{
					ans.push_back('D');
					k--;
				}
				else
				{
					ans.push_back('R');
					l--;
				}
			}
		}
	}
	else
	{
		k = N - 1;
		l = N - 1;
		while (k != 0 || l != 0)
		{
			if (k == 0)
			{
				ans.push_back('R');
				l--;
				continue;
			}
			if (l == 0)
			{
				ans.push_back('D');
				k--;
				continue;
			}
			if (k != 0 && l != 0)
			{
				if (d2[k - 1][l] < d2[k][l - 1])
				{
					ans.push_back('D');
					k--;
				}
				else
				{
					ans.push_back('R');
					l--;
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%c", ans[i]);
	return 0;
}