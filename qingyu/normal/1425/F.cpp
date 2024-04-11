// By Qingyu
#include <bits/stdc++.h>

const int N = 1e5 + 50;

int n, a[N];

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
	{
		printf("? %d %d\n", i - 1, i);
		fflush(stdout);
		scanf("%d", &a[i]);
	}
	printf("? 1 3\n");
	fflush(stdout);
	scanf("%d", &a[1]); a[1] -= a[3];
	for (int i = 2; i <= n; ++i) a[i] -= a[i - 1];
	printf("! ");
	for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
}