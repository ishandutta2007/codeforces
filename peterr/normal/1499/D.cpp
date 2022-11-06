#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E7;
vector<int> primes;
int sieve[MAXN + 1];

long long solve(int c, int d, int x, int y)
{
    x = x / y + d;
    if (x % c != 0)
        return 0;
    x /= c;
    int p = -1;
    int cnt = 0;
    while (x > 1)
    {
        if (sieve[x] != p)
        {
            cnt++;
            p = sieve[x];
        }
        x /= sieve[x];
    }
    return 1LL << cnt;
}

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
            if (primes[j] > sieve[i] || i * primes[j] > MAXN)
                break;
            sieve[i * primes[j]] = primes[j];
        }
    }
    /*
    for (int p : primes)
        cout << p << endl;
    */
    int t;
    cin >> t;
    while (t--)
    {
        int c, d, x;
        cin >> c >> d >> x;
        long long ans = 0;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i != 0)
                continue;
            ans += solve(c, d, x, i);
            if (i * i != x)
                ans += solve(c, d, x, x / i);
        }
        cout << ans << "\n";
    }
    return 0;
}