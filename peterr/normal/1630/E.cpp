#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 998244353;
const int MAXN = 1E6;
int fac[MAXN + 1];
int invfac[MAXN + 1];
int freq[MAXN + 1];
int c[MAXN + 1];

int mult(int n, vector<int> const& vec)
{
	int ans = fac[n];
	for (int x : vec)
		ans = (int) ((long long) ans * invfac[x] % MOD);
	return ans;
}

int modpow(int b, int e)
{
	int ans = 1;
	while (e)
	{
		if (e & 1)
			ans = (int) ((long long) ans * b % MOD);
		b = (int) ((long long) b * b % MOD);
		e >>= 1;
	}
	return ans;
}

int modinv(int x)
{
	return modpow(x, MOD - 2);
}

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++)
	{
		fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
	}
	invfac[MAXN] = modinv(fac[MAXN]);
	for (int i = MAXN - 1; i >= 0; i--)
	{
		invfac[i] = (int) ((long long) invfac[i + 1] * (i + 1) % MOD);
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		fill(freq + 1, freq + n + 1, 0);
		fill(c + 1, c + n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			freq[x]++;
		}
		if (*max_element(freq + 1, freq + n + 1) == n)
		{
			cout << "1\n";
			continue;
		}
		int fgcd = freq[1];
		for (int i = 1; i <= n; i++)
		{
			fgcd = __gcd(fgcd, freq[i]);
		}
		for (int i = 0; i < n; i++)
		{
			c[__gcd(i, n)]++;
		}
		int e = 0;
		int total = 0;
		for (int i = 1; i <= n; i++)
		{
			int ni = n / i;
			if (!c[i] || fgcd % ni != 0)
				continue;
			int ff = 0;	
			vector<int> f;
			for (int j = 1; j <= n; j++)
			{
				if (!freq[j])
					continue;
				f.push_back(freq[j] / ni);
				add(ff, f.back());
			}
			
			// total
			add(total, (int) ((long long) c[i] * mult(i, f) % MOD));
			
			// e
			ff = (int) ((long long) ff * ff % MOD);
			for (int x : f)
				add(ff, MOD - (int) ((long long) x * x % MOD));
			int temp = c[i];
			temp = (int) ((long long) temp * mult(i - 2, f) % MOD);
			temp = (int) ((long long) temp * ff % MOD);
			add(e, temp);
		}
		total = (int) ((long long) total * modinv(n) % MOD);
		//cout << "total " << total << endl;
		//cout << "e " << e << endl;
		int ans = (int) ((long long) e * modinv(total) % MOD);
		cout << ans << "\n";
	}
	return 0;
}