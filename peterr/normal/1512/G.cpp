#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E7;
int sieve[MAXN + 1];
vector<int> primes;
int ans[MAXN + 1];
long long sum[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
            sieve[i * primes[j]] = primes[j];
        }
    }
    fill(ans, ans + MAXN + 1, -1);
    sum[1] = 1;
    ans[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        int x = i;
        int prod = 1;
        int p = sieve[i];
        while (x % p == 0)
        {
            prod *= p;
            x /= p;
        }
        sum[i] = sum[i / p] + prod * sum[x];
        //sum[i] = (sieve[i] + 1) * sum[i / sieve[i]];
        if (sum[i] <= MAXN && ans[sum[i]] == -1)
            ans[sum[i]] = i;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}