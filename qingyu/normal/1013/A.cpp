#include <cstdio>

int n;
int a[100], b[100], ans;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < n; ++i) scanf("%d", b + i);
	for (int i = 0; i < n; ++i) ans += a[i] - b[i];
	if (ans >= 0) puts("Yes");
	else puts("No");
    return 0;
}
//TODO: FINISHED