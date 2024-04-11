#include<cstdio>
#include<vector>

using namespace std;

int n, k, a[100], used[1000], l;
vector <int> c[1000];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &a[i]);
		used[a[i]] = 1;
		c[i].push_back(a[i]);
	}
	l = 0;
	for (int i = 1; i <= n * k; i++)
	{
		if (used[i] == 0)
		{
			c[l].push_back(i);
			if ((int) c[l].size() == n)
				l++;
		}
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < (int) c[i].size(); j++)
			printf("%d ", c[i][j]);
		puts("");
	}
	return 0;
}