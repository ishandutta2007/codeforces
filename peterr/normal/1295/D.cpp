#include <bits/stdc++.h>

using namespace std;

long long process(long long endd, long long cur, vector<long long> &primes, int cnt, int ind, int sign)
{
    if (cnt == 0)
    {
        return endd / cur * sign;
    }
    else
    {
        long long ans = 0;
        for (int i = ind; i < (int) primes.size(); i++)
        {
            ans += process(endd, cur * primes[i], primes, cnt - 1, i + 1, sign);
        }
        return ans;
    }
}

long long coprime(long long endd, vector<long long> &primes)
{
    long long ans = 0;
    if (endd == 0)
        return 0LL;
    int sign = 1;
    for (int i = 1; i <= (int) primes.size(); i++)
    {
        ans += process(endd, 1, primes, i, 0, sign);
        sign *= -1;
    }
    return endd - ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, m;
        cin >> a >> m;
        long long g = __gcd(a, m);
        long long i1 = a / g;
        long long i2 = m / g;
        vector<long long> primes;
        long long temp = i2;
        for (long long i = 2; temp > 1 && i * i <= i2; i++)
        {
            if (temp % i == 0)
            {
                primes.push_back(i);
                while (temp % i == 0)
                    temp /= i;
            }
        }
        if (temp > 1)
            primes.push_back(temp);
        cout << coprime(i1 + i2 - 1, primes) - coprime(i1 - 1, primes) << endl;
    }
    return 0;
}