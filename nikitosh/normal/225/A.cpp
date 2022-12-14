#include<cstdio>

int N, k, l, m, a[1000];

int main()
{
	scanf("%d%d", &N, &k);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &l, &m);
		a[l] = 1;
		a[m] = 1;
		a[7 - l] = 1;
		a[7 - m] = 1;
	}
	if (a[k] == 1)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}