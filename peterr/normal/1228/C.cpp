#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXP = 1E5;
int isPrime[MAXP + 1];
vector<int> primes;
unordered_set<int> factors;

int pow(long long b, long long e)
{
    int exp = (int) (e % (MOD - 1));
    long long ans = 1;
    long long x = b % MOD;
    while (exp > 0)
    {
        if ((exp & 1) == 1)
        {
            ans = (((long long) ans * x) % MOD);
        }
        exp = exp >> 1;
        x = (((long long) x * x) % MOD);
    }
    return ans;
}

int main()
{
    for (int i = 2; i <= MAXP; i++)
    {
        if (isPrime[i] == 0)
        {
            primes.push_back(i);
            isPrime[i] = i;
            if ((long long) i * i > MAXP)
                continue;
            for (int j = i * i; j <= MAXP; j += i)
            {
                isPrime[j] = i;
            }
        }
    }
    int x;
    long long n;
    cin >> x >> n;
    for (int i = 0; i < (int) primes.size() && x > 1; i++)
    {
        while (x % primes[i] == 0)
        {
            //cout << primes[i] << " " << "yay" << endl;
            x /= primes[i];
            factors.insert(primes[i]);
        }
    }
    if (x > 1)
    {
        factors.insert(x);
    }
    long long ans = 1;
    for (int f : factors)
    {
        //cout << "factor " << f << endl;
        long long temp = f;
        while (temp <= n && temp > (long long) 0)
        {
            ans = (((long long) ans * pow((long long) f, n / temp)) % MOD);
            if (temp > n / f)
                break;
            temp = temp * f;
        }
    }
    cout << ans << endl;
    return 0;
}