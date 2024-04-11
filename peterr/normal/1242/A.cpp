#include <bits/stdc++.h>

using namespace std;

const long long MAXN = (long long) 1E12;
const int MAXP = (int) 1E6;
bool isPrime[MAXP + 1];
vector<int> primes;

int main()
{
    fill(isPrime + 2, isPrime + MAXP + 1, true);
    for (int i = 2; i <= MAXP; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            if ((long long) i * i <= MAXP)
            {
                for (int j = i * i; j <= MAXP; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }
    long long n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    vector<long long> p;
    for (int prime : primes)
    {
        if (n % prime == 0)
        {
            p.push_back(prime);
            while (n % prime == 0)
                n /= prime;
        }
    }
    if (n > 1)
        p.push_back(n);
    if ((int) p.size() == 1)
    {
        cout << p[0] << endl;
    }
    else
    {
        cout << 1 << endl;
    }
    return 0;
}