#include <cstdio>
#include <algorithm>

int c[101000], tot = 0;
int Max[101000];
int a[101000], b[101000];

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int cnt = k;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		if(Max[a[i]] == 0) cnt--, Max[a[i]] = b[i];
		else if(Max[a[i]] < b[i]) c[++tot] = Max[a[i]], Max[a[i]] = b[i];
		else c[++tot] = b[i];
	}
	std::sort(c + 1, c + tot + 1);
	long long ans = 0;
	for(int i = 1; i <= cnt; i++)
		ans += c[i];
	printf("%lld\n", ans);
	return 0;
}