#include<cstdio>

int k, p[200], m, a[200][200], q;

int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);                
	scanf("%d", &k);
	for (int i = 0; i < 101; i++)
	{
		p[i] = i * (i - 1) * (i - 2) / 6;
		//printf("i = %d p[i] = %d\n", i, p[i]);
	}
	for (int i = 0; i < 101; i++)
		if (k < p[i])
		{
			m = i;
			break;
		}
	m--;              
	//printf("%d\n", m);      
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			if (i != j)
				a[i][j] = 1;
	k -= p[m];        
	//printf("%d\n", m);
	//if (k == 0)
	//	m++;
	while (k != 0)
	{
		for (int i = m - 2; i >= 0; i--)
			if (i * (i - 1) / 2 <= k) 
			{
				q = i;
				break;
			}
	 	k -= q * (q - 1) / 2;
	 	//printf("%d\n", m);     
	 	for (int i = 0; i < q; i++)
	 		a[m][i] = 1;
	 	m++;
	 	//printf("%d %d\n", q, k);
	}	
	printf("%d\n", m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j > i)
				a[i][j] = a[j][i];
			printf("%d", a[i][j]);
		}
		puts("");
	}
	//int ans = 0;
	//for (int i = 0; i < m; i++)
	//	for (int j = i + 1; j < m; j++)
	//		for (int g = j + 1; g < m; g++)
	//			if (a[j][i] == 1 && a[j][g] == 1 && a[g][i] == 1)
	//				ans++;
	//printf("%d\n", ans);
	return 0;
}