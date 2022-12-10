#include <bits/stdc++.h>

#define N 200005
#define Mo 998244353

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int n, m, a[N], b[N], cnt[N];

int fac[N], inv[N];

int power(int x, int y)
{
	int s = 1;
	for (; y; y >>= 1)
	{
		if (y & 1) s = 1ll * s * x % Mo;
		x = 1ll * x * x % Mo; 
	}
	return s;
}

int ans = 0, tr[N];

int lowbit(int x) { return x & -x; } 

void add(int x, int y)
{
	for (; x < N; x += lowbit(x)) tr[x] += y;
}

int ask(int x)
{
	int s = 0;
	for (; x; x -= lowbit(x)) s += tr[x];
	return s;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), cnt[a[i]]++;
	for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
	fac[0] = 1; for (int i = 1; i < N; ++i) fac[i] = 1ll * fac[i - 1] * i % Mo;
	inv[N - 1] = power(fac[N - 1], Mo - 2);
	for (int i = N - 2; i >= 0; --i) inv[i] = 1ll * inv[i + 1] * (i + 1) % Mo;
	int s = 1;
	for (int i = 1; i < N; ++i) s = 1ll * s * inv[cnt[i]] % Mo, add(i, cnt[i]);
	for (int i = 1; i <=min(n, m); ++i)
	{
		//less than a[i]
		(ans += 1ll * fac[n - i] * s % Mo * ask(b[i] - 1) % Mo) %= Mo; 
		//equal to a[i]
		if (cnt[b[i]])
		{
			s = 1ll * s * cnt[b[i]] % Mo;
			cnt[b[i]]--;
			add(b[i], -1);
			if (i == n && i < m) (ans += 1) %= Mo;
		}
		else break;
	}
	printf("%d\n", ans);
}