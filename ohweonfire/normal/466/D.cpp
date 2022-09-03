#include <cstdio>
#define maxn 2005
#define mod 1000000007
typedef long long LL;
int a[maxn];
int n, m;
int main(void)
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) a[i] = m - a[i];
	for(int i = 1; i <= n; i++) if(a[i] < 0) {
		printf("0\n");
		return 0;
	}
	a[0] = a[n+1] = 0;
	LL ans = 1;
	for(int i = 1; i <= n + 1; i++) {
		if(a[i] == a[i-1] + 1) continue;
		if(a[i] == a[i-1]) ans = ans * (a[i] + 1) % mod;
		else if(a[i] == a[i-1] - 1) ans = ans * a[i-1] % mod;
		else {
			printf("0\n");
			return 0;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}