#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
const int MOD = 998244353;
int dp[MAXN + 1];
int sieve[MAXN + 1];
vector<int> primes;

void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main()
{
    for (int i = 2; i <= MAXN; i++)
    {
        if (!sieve[i])
        {
            sieve[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int) primes.size(); j++)
        {
            if (primes[j] > sieve[i] || primes[j] * i > MAXN)
                break;
            sieve[primes[j] * i] = primes[j];
        }
    }
    int n;
    cin >> n;
    dp[1] = 1;
    int sum = 1;
    for (int i = 2; i <= n; i++)
    {
        int two = 1;
        int j = i;
        while (j > 1)
        {
            int cnt = 1;
            int p = sieve[j];
            while (j % p == 0)
            {
                j /= p;
                cnt++;
            }
            two = (int) ((long long) two * cnt % MOD);
        }
        dp[i] = sum;
        add(dp[i], two);
        add(sum, dp[i]);
    }
    cout << dp[n] << "\n";
    return 0;
}