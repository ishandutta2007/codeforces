#include <bits/stdc++.h>

using namespace std;

long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

long long lcm(long long x, long long y)
{
    return x * y / gcd(x, y);
}

int main()
{
    long long a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    long long diff = b - a;
    vector<long long> factors;
    for (long long i = 1; i * i <= diff; i++)
    {
        if (diff % i == 0)
        {
            factors.push_back(i);
            if (i * i != diff)
                factors.push_back(diff / i);
        }
    }

    long long ans = 0;
    long long low = lcm(a, b);
    for (long long f : factors)
    {
        long long n = max((long long) 0, (a - f + diff - 1) / diff);
        long long k = (f + n * diff) - a;
        long long mult = lcm(a + k, b + k);
        if (mult < low)
        {
            low = mult;
            ans = k;
        }
        else if (mult == low && k < ans)
        {
            ans = k;
        }
    }
    cout << ans;

    return 0;
}