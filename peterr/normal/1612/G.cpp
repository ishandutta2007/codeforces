#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 5E5;
int c[MAXN];
int fac[MAXN + 1];

void add(int &x, int y)
{
	if (y < 0)
		y += MOD;
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int ari(long long x)
{
	x %= MOD;
	return (int) ((long long) x * (x + 1) / 2 % MOD);
}

int ari(long long x, long long y)
{
	if (x)
	{
		int ans = ari(y);
		add(ans, MOD - ari(x - 1));
		return ans;
	}
	return ari(y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++)
		fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
	int m;
	cin >> m;
	long long sum = 0;
	map<int, int> mp;
	for (int i = 0; i < m; i++)
	{
		cin >> c[i];
		sum += c[i];
		mp[c[i] - 1]++;
		mp[-(c[i] - 1) - 2]--;
	}
	int ans1 = 0;
	int ans2 = 1;
	for (int i = 2 * MAXN; i >= -2 * MAXN; i--)
	{
		int num = mp[i];
		if (num)
		{
			add(ans1, (int) ((long long) ari(sum - num + 1, sum) * i % MOD));
			ans2 = (int) ((long long) ans2 * fac[num] % MOD);
		}
		sum -= num;
		mp[i - 2] += num;
		//if (ans1 < 0)
			//cout << "neg " << i << " " << ans1 << endl;
	}
	cout << ans1 << " " << ans2 << "\n";
	return 0;
}