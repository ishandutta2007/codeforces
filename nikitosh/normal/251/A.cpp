#include<cstdio>
#include<algorithm>

using namespace std;

int n, d, a[100005], l, r;
long long ans;

int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		l = upper_bound(a, a + n, a[i] + d)	- a - 1;
		r = l - i;
		ans += (long long) r * (long long) (r - 1) / (long long) 2;
	}
	printf("%I64d", ans);
	return 0;
}