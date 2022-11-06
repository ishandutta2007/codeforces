#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MAXA = 1E6;
int sieve[MAXA + 1];
vector<int> primes;
int a[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i <= MAXA; i++)
	{
		if (!sieve[i])
		{
			sieve[i] = i;
			primes.push_back(i);
		}
		for (int j = 0; j < (int) primes.size(); j++)
		{
			if (primes[j] > sieve[i] || i * primes[j] > MAXA)
				break;
			sieve[primes[j] * i] = primes[j];
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n, e;
		cin >> n >> e;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 1 || sieve[a[i]] != a[i])
				continue;
			int lt = 0;
			int rt = 0;
			for (int j = i - e; j >= 0; j -= e)
			{
				if (a[j] != 1)
					break;
				lt++;
			}
			for (int j = i + e; j < n; j += e)
			{
				if (a[j] != 1)
					break;
				rt++;
			}
			ans += ((long long) lt + 1) * (rt + 1) - 1;
		}
		cout << ans << "\n";
	}
	return 0;
}