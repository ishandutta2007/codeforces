#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, c[100005], used[100005], a, b, ans[100005], max1 = - (int) 1e9;
vector <int> d[100005];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
		used[c[i]] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		a--;
		b--;
		if (c[a] != c[b])
		{
			d[c[a]].push_back(c[b]);
			d[c[b]].push_back(c[a]);
		}
	}             
	for (int i = 1; i < 100001; i++)
	{
		if (used[i] == 1)
		{                     
			sort(d[i].begin(), d[i].end());
			if ((int) d[i].size() != 0)
				ans[i] = 1;
			
			for (int j = 1; j < (int) d[i].size(); j++)
				if (d[i][j] != d[i][j - 1])
					ans[i]++; 		
			//printf("i = %d ans[i] = %d\n", i, ans[i]);
			max1 = max(max1, ans[i]);
		}
	}
	for (int i = 1; i < 100001; i++)
		if (ans[i] == max1 && used[i] == 1)
		{
			printf("%d\n", i);
			return 0;
		}
	return 0;
}