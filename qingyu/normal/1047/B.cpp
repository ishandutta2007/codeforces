#include <bits/stdc++.h>

constexpr int N = 5e6 + 50;
int n;
char s[N];
long long ans;

int main() 
{
	int T, ans = -10000000;
	scanf("%d", &T);
	while (T--)
	{
		int x, y; scanf("%d%d", &x, &y);
		ans = std::max(ans, x + y);
	}
	printf("%d", ans);
}