#include<cstdio>

int n, m, x[1000000], y[1000000], i, j, g, b, a[2000][2000];

int main()
{
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		a[x[i] + 1][y[i] + 1] = 1;
		b = 1;
		for (j = x[i] - 1; j < x[i] + 2; j++)
			for (g = y[i] - 1; g < y[i] + 2; g++)
				if (a[j][g] == 0)
					b = 0; 
		if (b == 1)
		{
			printf("%d\n", i + 1);
			return 0;
		}
		b = 1;
		for (j = x[i]; j < x[i] + 3; j++)
			for (g = y[i] - 1; g < y[i] + 2; g++)
				if (a[j][g] == 0)
					b = 0; 
		if (b == 1)
		{
			printf("%d\n", i + 1);
			return 0;
		}
		b = 1;
		for (j = x[i] + 1; j < x[i] + 4; j++)
			for (g = y[i] - 1; g < y[i] + 2; g++)
				if (a[j][g] == 0)
					b = 0; 
		if (b == 1)
		{
			printf("%d\n", i + 1);
			return 0;
		} 
		b = 1;
		for (j = x[i] - 1; j < x[i] + 2; j++)
			for (g = y[i]; g < y[i] + 3; g++)
				if (a[j][g] == 0)
					b = 0; 
		if (b == 1)
		{
			printf("%d\n", i + 1);
			return 0;
		}
		b = 1;
		for (j = x[i]; j < x[i] + 3; j++)
			for (g = y[i]; g < y[i] + 3; g++)
				if (a[j][g] == 0)
					b = 0; 
		if (b == 1)
		{
			printf("%d\n", i + 1);
			return 0;
		}
		b = 1;
		for (j = x[i] + 1; j < x[i] + 4; j++)
			for (g = y[i]; g < y[i] + 3; g++)
				if (a[j][g] == 0)
					b = 0; 
		if (b == 1)
		{
			printf("%d\n", i + 1);
			return 0;
		}
		b = 1;
		for (j = x[i] - 1; j < x[i] + 2; j++)
			for (g = y[i] + 1; g < y[i] + 4; g++)
				if (a[j][g] == 0)
					b = 0; 
		if (b == 1)
		{
			printf("%d\n", i + 1);
			return 0;
		}
		b = 1;
		for (j = x[i]; j < x[i] + 3; j++)
			for (g = y[i] + 1; g < y[i] + 4; g++)
				if (a[j][g] == 0)
					b = 0; 
		if (b == 1)
		{
			printf("%d\n", i + 1);
			return 0;
		}
		b = 1;
		for (j = x[i] + 1; j < x[i] + 4; j++)
			for (g = y[i] + 1; g < y[i] + 4; g++)
				if (a[j][g] == 0)
					b = 0; 
		if (b == 1)
		{
			printf("%d\n", i + 1);
			return 0;
		}
           
	}
	printf("%d\n", -1);
	return 0;
}