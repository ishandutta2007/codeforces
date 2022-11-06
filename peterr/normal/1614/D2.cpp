#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MAXA = 2E7;
int a[MAXN];
int mobius[MAXA + 1];
int sieve[MAXA + 1];
vector<int> primes;
long long ans[MAXA + 1];
long long num[MAXA + 1];

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
			mobius[i] = 1;
		}
		for (int j = 0; j < (int) primes.size(); j++)
		{
			if (primes[j] * i > MAXA || primes[j] > sieve[i])
				break;
			sieve[primes[j] * i] = primes[j];
			if (primes[j] == sieve[i])
				mobius[primes[j] * i] = 0;
			else
				mobius[primes[j] * i] = -mobius[i];
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		num[a[i]]++;
	}
	for (int p : primes)
	{
		for (int i = MAXA / p; i >= 1; i--)
		{
			num[i] += num[i * p];
		}
	}
	sort(a, a + n);
	int ptr = n - 1;
	for (int i = MAXA; i >= 1; i--)
	{
		while (ptr >= 0 && a[ptr] == i)
		{
			ans[i] += i;
			ptr--;
		}
		//for (int j = 2; j * i <= MAXA; j++)
		//{
			//num[i] += num[j * i] * mobius[j];
		//}
		for (int j : primes)
		{
			if (j * i > MAXA)
				break;
			ans[i] = max(ans[i], ans[j * i] + (long long) (num[i] - num[j * i]) * i);
		}
	}
	cout << ans[1] << "\n";
	return 0;
}