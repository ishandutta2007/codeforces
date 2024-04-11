#include <bits/stdc++.h>

const int N = 2e6 + 50;
const int mod = 1004535809;
int n, a[N], t, bs, h[N], pw[N];
int q[N], T;
char s[N];
std::mt19937 rnder(std::chrono::steady_clock::now().time_since_epoch().count());

inline int rnd(int l, int r)
{
	return std::uniform_int_distribution<int>(l, r)(rnder);
}

inline int get(int l, int r)
{
	return (h[r] - 1ll * h[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

inline bool check(int l1, int l2)
{
	int l = 1, r = n, res = 0;
	while (l <= r)
	{
		const int mid = l + r >> 1;
		if (get(l1, l1 + mid - 1) == get(l2, l2 + mid - 1))
			l = (res = mid) + 1;
		else
			r = mid - 1;
	}
	if (res == n)
		return 0;
	return s[l1 + res] < s[l2 + res];
}

int main()
{
	bs = rnd(114514, 1919810);
	scanf("%s", s + 1), n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		t += s[i] == '(' ? 1 : -1, s[i + n] = s[i];
	for (int i = *pw = 1; i <= 2 * n; ++i)
		pw[i] = 1ll * pw[i - 1] * bs % mod, h[i] = (1ll * h[i - 1] * bs + s[i]) % mod;
	if (t >= 0)
	{
		for (int i = 1; i <= 2 * n; ++i)
			a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
		int ans = 0, p = 1;
		for (int i = 1; i <= 2 * n; ++i)
		{
			while (p <= T && a[i] <= a[q[T]])
				--T;
			q[++T] = i;
			while (p <= T && i - q[p] + 1 > n)
				++p;
			if (p <= T && i > n && a[i - n] <= a[q[p]])
			{
				if (!ans || check(i - n + 1, ans))
					ans = i - n + 1;
			}
		}
		for (int i = 1; i <= n; ++i)
			putchar(s[ans + i - 1]);
		while (t--)
			putchar(')');
	} else
	{
		for (int i = 2 * n; i; --i)
			a[i] = a[i + 1] + (s[i] == '(' ? -1 : 1);
		int ans = 0, p = 1;
		for (int i = 2 * n; i; --i)
		{
			while (p <= T && a[i] <= a[q[T]])
				--T;
			q[++T] = i;
			while (p <= T && q[p] - i + 1 > n)
				++p;
			if (p <= T && i <= n && a[i + n] <= a[q[p]])
			{
				if (!ans || check(i, ans))
					ans = i;
			}
		}
		while (t++)
			putchar('(');
		for (int i = 1; i <= n; ++i)
			putchar(s[ans + i - 1]);
	}
	return 0;
}