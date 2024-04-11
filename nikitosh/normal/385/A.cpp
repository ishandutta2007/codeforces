#include<cstdio>
#include<algorithm>

using namespace std;

int n, c, a[1005], ans;

int main()
{
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	ans = 0;
	for (int i = 0; i < n - 1; i++)
		ans = max(ans, a[i] - a[i + 1] - c);
	printf("%d\n", ans);
	return 0;
}