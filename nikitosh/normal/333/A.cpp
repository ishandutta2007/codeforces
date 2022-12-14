#include<cstdio>

long long n, t[100];

int main()
{
	scanf("%I64d", &n);
	t[0] = 1;
	for (int i = 1; i < 40; i++)
		t[i] = t[i - 1] * 3;
	for (int i = 1; i < 40; i++)
	{
		if (n % t[i] != 0)
		{
			printf("%I64d\n", n / t[i] + 1);
			return 0;
		}
	}
	return 0;
}