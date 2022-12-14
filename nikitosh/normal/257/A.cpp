#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, k, size, ans, a[10000];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	ans = 0;
	size = k;
	int i1 = n - 1;
	while (size < m && ans < n)
	{
		size += a[i1] - 1;
		i1--;	
		ans++;
	}
	if (size < m)
	{
		printf("%d\n", -1);
		return 0;
	}
	printf("%d\n", ans);
	return 0;
}