#include <bits/stdc++.h>

const int N = 1e5 + 50;

char s[N];
int stones[N], n;
void auth(int n, int a, int b)
{
	for (int i = 1; i <= n; ++i) assert((a <= stones[i] && stones[i] < 2 * b) || stones[i] < b);
}
bool gg(int w, int a, int b)
{
	return (b <= w && w < a) || (w >= 2 * b);	
}
bool solve()
{
	int a, b, _; n = 0;
	scanf("%d%d%s", &a, &b, s + 1); _ = strlen(s + 1);
	for (int cur = 0, i = 1; i <= _ + 1; ++i)
	{
		if (s[i] != '.')
		{
			if (cur) stones[++n] = cur, cur = 0;
		}
		else ++cur;
	}

	int killed = 0, available = 0;
	//for (int i = 1; i <= n; ++i) printf("stones[%d] = %d\n", i, stones[i]);
	for (int i = 1; i <= n; ++i)
	{
		int now = stones[i];
		if (b <= now && now < a) return false;
		else if (now >= 2 * b)
		{
			if (!killed) killed = i;
			else return false;
		}
		else if (a <= now && now < 2 * b) ++ available;
	}
	if (!killed) return (available & 1);
	int current = stones[killed];
	for (int left = 0; current - left - a >= 0; ++left)
	{
		int right = current - left - a;
		if (gg(left, a, b) || gg(right, a, b)) continue;
		int now = available + (left >= a) + (right >= a);
		if (!(now & 1)) return true;
	}
	return false;
	
}

int main()
{
	int _;
	scanf("%d", &_);
	while (_--) puts(solve() ? "YES" : "NO");
}