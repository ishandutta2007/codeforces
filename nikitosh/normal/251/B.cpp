#include<cstdio>
#include<algorithm>

using namespace std;

int n, k, a1[200], a2[200], s[200], d1[200][200], d2[200][200], l1, l2, boo1, boo2, bo1[200], bo2[200], m, k1, k2, boo, booo;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	if (n == 1 && k == 1)
	{
		printf("NO\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a1[i]);
		d1[0][i] = i + 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			{
				if (a1[j] == i + 1)
					a2[i] = j + 1;
			}
	booo = 0;
	for (int i = 0; i < n; i++)
		if (a1[i] != a2[i])
			booo = 1;
	//for (int i = 0; i < n; i++)
	//	printf("%d ", a2[i]);	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
		d2[0][i] = i + 1;
	}
		
	if (k == 1)
	{
		boo1 = 0;
		boo2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != a1[i])
				boo1 = 1;
			if (s[i] != a2[i])
				boo2 = 1;
		}
		if (boo1 == 0 || boo2 == 0)
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}

	boo = 0;
	for (int i = 0; i < n; i++)
		if (s[i] != i)
			boo = 1;
	if (boo == 0)
	{
		printf("NO\n");
		return 0;	
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
			d1[i][j] = d1[i - 1][a1[j] - 1];
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
			d2[i][j] = d2[i - 1][a2[j] - 1];
	}
	//for (int i = 0; i < n; i++)
	//	printf("%d ", d2[1][i]);
	for (int i = 0; i <= k; i++)
	{
		boo1 = 0;    
		for (int j = 0; j < n; j++)
			if (d1[i][j] != s[j])
				boo1 = 1;
		if (boo1 == 0)
		{
			bo1[i] = 1; 
		}
	}
	l1 = k + 1;
	for (int i = 0; i <= k; i++)
		if (bo1[i] == 1)
		{
			l1 = i;
			break;
		}
	for (int i = 0; i <= k; i++)
	{
		boo2 = 0;    
		for (int j = 0; j < n; j++)
			if (d2[i][j] != s[j])
				boo2 = 1;
		if (boo2 == 0)
		{            
			bo2[i] = 1;
		}
	}
	l2 = k + 1;
	for (int i = 0; i <= k; i++)
		if (bo2[i] == 1)
		{
			l2 = i;
			break;
		}
	//printf("%d %d\n", l1, l2);
	if (booo == 0)
	{
	for (int i = 0; i <= k; i++)
	{
		k1 = i;
		k2 = k - i;
		if (k1 >= k2)
		{
			m = k1 - k2;
			if (bo1[m] == 1 && max(m, 2) <= l1)
			{
				printf("YES\n");
				return 0;
			}          
		}
		else
		{
			m = k2 - k1;
			if (bo2[m] == 1 && max(m, 2) <= l2)
			{
				printf("YES\n");
				return 0;
			}          
		}
	}
	}
	else
	{
	for (int i = 0; i <= k; i++)
	{
		k1 = i;
		k2 = k - i;
		if (k1 >= k2)
		{
			m = k1 - k2;
			if (bo1[m] == 1 && max(m, 1) <= l1)
			{
				printf("YES\n");
				return 0;
			}          
		}
		else
		{
			m = k2 - k1;
			if (bo2[m] == 1 && max(m, 1) <= l2)
			{
				printf("YES\n");
				return 0;
			}          
		}
	}
	}
	printf("NO\n");
	return 0;
}