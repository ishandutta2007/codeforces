#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int LOGN = 40;
const int MAXN = 2E5;
int twopow[MAXN + 1];
int freq[LOGN];
int fac[MAXN + 1];

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

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
	int ans = (int) ((long long) fac[n] * modinv(fac[k]) % MOD);
	return (int) ((long long) ans * modinv(fac[n - k]) % MOD);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	twopow[0] = 1;
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++)
	{
		twopow[i] = (int) ((long long) twopow[i - 1] * 2 % MOD);
		fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
	}
	int n;
	cin >> n;
	int odd = 0;
	int even = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x & 1)
			odd++;
		else
		{
			even++;
			int cnt = 0;
			while (x % 2 == 0)
			{
				cnt++;
				x /= 2;
			}
			freq[cnt]++;
		}
	}
	int ans = (int) ((long long) (twopow[odd] - 1) * twopow[even] % MOD);
	int ways = 1;
	for (int i = LOGN - 1; i >= 1; i--)
	{
		int amt = freq[i];
		for (int j = 2; j <= amt; j += 2)
		{
			add(ans, (int) ((long long) ways * choose(amt, j) % MOD));
		}
		ways = (int) ((long long) ways * twopow[freq[i]] % MOD);
	}
	cout << ans << "\n";
	return 0;
}