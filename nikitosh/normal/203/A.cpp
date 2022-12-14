#include<cstdio>

int x, t, a, b, da, db, aaa[10000], bbb[10000], i, j, y, z;

int main()
{
	scanf("%d%d%d%d%d%d", &x, &t, &a, &b, &da, &db);
	for (i = 0; i < t; i++)
	{
		aaa[y] = a - i * da;
		y++;		
	}
	aaa[y] = 0;
	y++;
	for (i = 0; i < t; i++)
	{
		bbb[z] = b - i * db;
		z++;		
	}
	bbb[z] = 0;
	z++;
	for (i = 0; i < y; i++)
		for (j = 0; j < z; j++)
			if (aaa[i] + bbb[j] == x)
			{
				printf("YES\n");
				return 0;
			}
	printf("NO\n");
	return 0;
}