#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int n, a[200], s, t, s2, t2, sum = 0, ans = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	scanf("%d%d", &s2, &t2);
	s2--;
	t2--;
	s = min(s2, t2);
	t = max(s2, t2);
	for (int i = s; i < t; i++)
		ans += a[i];
	printf("%d\n", min(ans, sum - ans));
	return 0;
}