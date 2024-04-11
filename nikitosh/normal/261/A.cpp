#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, q[200000], a[200000], min1 = (int) 1e9, ans = 0, ans2 = 0;

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &q[i]);
		min1 = min(min1, q[i]);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	n--;
	while (n >= 0)
	{
		if (ans == min1)
		{
			ans = 0;
			n -= 2;
			continue;
		}
		ans2 += a[n];
		n--;
		ans++;
	}
	printf("%d\n", ans2);
	return 0;
}