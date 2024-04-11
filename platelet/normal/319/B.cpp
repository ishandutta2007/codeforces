#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define rep(i, j, k) for(int i = j; i <= k; i++)
#define rep2(i, j, k) for(int i = j; i >= k; i--)
const int N = 1e5 + 5;
int a[N], l[N], v[N];
int main()
{
	int n, ans = 0; scanf("%d", &n);
	rep(i, 1, n)
	{
		scanf("%d", &a[i]); l[i] = i - 1; v[i] = 0;
		while(l[i] && a[l[i]] <= a[i]) v[i] = max(v[i], v[l[i]]), l[i] = l[l[i]];
		if(l[i]) ans = max(ans, ++v[i]);
	}
	printf("%d\n", ans);
	return 0;
}