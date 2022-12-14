#include<cstdio>
#include<vector>

using namespace std;

int a[700000], n;
vector <int> c[10000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
	{
		scanf("%d", &a[i]);
		c[a[i]].push_back(i + 1);
	}
	for (int i = 1; i <= 5000; i++)
	{
		if ((int) c[i].size() % 2 == 1)
		{
			printf("%d\n", -1);
			return 0;
		}
 	}
	for (int i = 1; i <= 5000; i++)
	{
  	for (int j = 0; j < (int) c[i].size(); j += 2)
  	{
  		printf("%d %d\n", c[i][j], c[i][j + 1]);
  	}
	}
	return 0;
}