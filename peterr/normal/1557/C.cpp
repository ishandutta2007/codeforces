#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 2E5;
int fac[MAXN + 1];
int invfac[MAXN + 1];

int modpow(int b, int e)
{
	int ans = 1;
	while (e)
	{
		if (e & 1)
			ans = (int) ((long long) ans * b % MOD);
		e >>= 1;
		b = (int) ((long long) b * b % MOD);
	}
	return ans;
}

int modinv(int x)
{
	return modpow(x, MOD - 2);
}

int choose(int n, int k)
{
	if (k > n)
		return 0;
	int ans = (int) ((long long) fac[n] * invfac[k] % MOD);
	return (int )((long long) ans * invfac[n - k] % MOD);
}

void add(int& x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0] = invfac[0] = 1;
	for (int i = 1; i <= MAXN; i++)
	{
		fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
		invfac[i] = modinv(fac[i]);
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		if (n & 1)
		{
			int ways = 1;
			for (int i = 0; i <= n; i += 2)
			{
				add(ways, choose(n, i));
			}
			int ans = modpow(ways, k);
			cout << ans << "\n";
		}
		else
		{
			int zero = 0;
			int anything = modpow(2, n);
			for (int i = 0; i < n; i += 2)
			{
				add(zero, choose(n, i));
			}
			int ans = modpow(zero, k);
			int before = 1;
			for (int i = 0; i < k; i++)
			{
				int ways = modpow(zero, i);
				ways = (int) ((long long) ways * modpow(anything, k - i - 1) % MOD);
				add(ans, ways);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}