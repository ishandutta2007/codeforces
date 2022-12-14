#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, k, a[100005], b[100005], a2[100005], b2[100005];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	if (n > m)
	{
		printf("YES\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + m);
	for (int i = 0; i < n; i++)
		a2[i] = a[n - i - 1];
	for (int i = 0; i < m; i++)
		b2[i] = b[m - i - 1];
	for (int i = 0; i < min(n, m); i++)
		if (a2[i] > b2[i])
		{
			printf("YES\n");
			return 0;
		}
	printf("NO\n");
	return 0;
}