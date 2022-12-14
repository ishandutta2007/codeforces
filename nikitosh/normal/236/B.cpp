#include<cstdio>

int a, b, c, del[1000005], ans = 0, pr[2000], size;

int d(int k)
{
	int ans2 = 1; 
	for (int i = 0; i < size; i++)
	{
		int ans1 = 0;
		while (k % pr[i] == 0)
		{
			ans1++;
			k /= pr[i];	
		}
		ans2 *= (ans1 + 1);
	}	
	if (k != 1)
		ans2 *= 2;
	return ans2;
}

int prime(int l)
{
	for (int i = 2; i * i <= l; i++)
		if (l % i == 0)
			return 0;
	return 1;	
}

int main()
{
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 2; i < 1000; i++)
		if (prime(i) == 1)
			pr[size++] = i;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)	
			for (int g = 1; g <= c; g++)
			{
				if (del[i * j * g] == 0)
					del[i * j * g] = d(i * j * g);
				ans = (ans + del[i * j * g]) % 1073741824;                     
			}
	printf("%d\n", ans);
	return 0;
}