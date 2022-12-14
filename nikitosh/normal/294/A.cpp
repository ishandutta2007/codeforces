#include<cstdio>

int N, M, x, y, a[10000];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
	 	scanf("%d%d", &x, &y);
	 	a[x - 1] += y - 1;
	 	a[x + 1] += a[x] - y;
	 	a[x] = 0;
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", a[i]);
	return 0;
}