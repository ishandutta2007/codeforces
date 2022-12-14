#include<cstdio>
#include<vector>

using namespace std;

int n, k, a[200000], str = 0, S, min1 = 1000000000, l;
vector <int> c1[200000], c2[200000];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
 	for (int i = 1; i < n; i++)
 		if (a[i] != a[i - 1])
 			str++;
	c1[a[0]].push_back(0);        
	if (a[0] != a[1])
		c2[a[0]].push_back(0);
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] != a[i - 1])
			c1[a[i]].push_back(i);
		if (a[i] != a[i + 1])
			c2[a[i]].push_back(i);
	}                             
	if (a[n - 1] != a[n - 2])
		c1[a[n - 1]].push_back(n - 1);
	c2[a[n - 1]].push_back(n - 1);
	/*for (int i = 1; i <= k; i++)
		for (int j = 0; j < (int) c1[i].size(); j++)
			printf("%d %d %d\n", i, c1[i][j], c2[i][j]);
	*/
	for (int i = 1; i <= k; i++)
	{
		S = str;
		S -= c1[i].size();  

		for (int j = 0; j < (int) c1[i].size(); j++)
		{
			if (c1[i][j] != 0 && c2[i][j] != n - 1)
			if (a[c1[i][j] - 1] == a[c2[i][j] + 1])
				S--;	
		}
		//printf("%d\n", S);
		if (S < min1)
		{
			min1 = S;
			l = i;
		}
	}
	printf("%d\n", l);
	return 0;
}