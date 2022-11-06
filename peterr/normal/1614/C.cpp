#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MOD = 1E9 + 7;
int cnt[30];
int freq[30];
int fac[MAXN + 1];
int invfac[MAXN + 1];
int twopow[MAXN + 1];

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

int choose(int n, int k)
{
	int ans = (int) ((long long) fac[n] * invfac[k] % MOD);
	return (int) ((long long) ans * invfac[n - k] % MOD);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0] = 1;
	twopow[0] = 1;
	for (int i = 1; i <= MAXN; i++)
	{
		fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
		twopow[i] = (int) ((long long) twopow[i - 1] * 2 % MOD);
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
		fill(cnt, cnt + 30, 0);
		fill(freq, freq + 30, 0);
		int n, m;
		cin >> n >> m;
		vector<tuple<int, int, int>> events;
		for (int i = 0; i < m; i++)
		{
			int l, r, x;
			cin >> l >> r >> x;
			events.push_back({l, x, 1});
			events.push_back({r + 1, x, 0});
		}
		sort(events.rbegin(), events.rend());
		for (int i = 1; i <= n; i++)
		{
			while (events.size() && get<0>(events.back()) == i)
			{
				tuple<int, int, int> tup = events.back();
				int x = get<1>(tup);
				if (get<2>(tup) == 1)
				{
					for (int j = 0; j < 30; j++)
					{
						if (!(x & (1 << j)))
						{
							freq[j]++;
						}
					}
				}
				else
				{
					for (int j = 0; j < 30; j++)
					{
						if (!(x & (1 << j)))
						{
							freq[j]--;
						}
					}
				}
				events.pop_back();
			}
			for (int j = 0; j < 30; j++)
			{
				if (!freq[j])
					cnt[j]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < 30; i++)
		{
			//cout << "cnt " << i << " " << cnt[i] << endl;
			int two = twopow[n - cnt[i]];
			for (int j = 1; j <= cnt[i]; j += 2)
			{
				int cont = (int) ((long long) two * choose(cnt[i], j) % MOD);
				cont = (int) ((long long) cont * (1 << i) % MOD);
				//cout << "cont " << j << " " << cont << endl;
				ans += cont;
				if (ans >= MOD)
					ans -= MOD;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}