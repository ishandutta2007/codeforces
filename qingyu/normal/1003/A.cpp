#include <cstdio>
int buc[105], n, ans, x;
int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &x);
		++buc[x];
		ans = buc[x] > ans ? buc[x] : ans;
	}
	printf("%d", ans);
}