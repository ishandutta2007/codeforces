#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int sieve[MAXN];
vector<int> primes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i < MAXN; i++)
    {
        if (!sieve[i])
            sieve[i] = i, primes.push_back(i);
        for (int j = 0; j < (int) primes.size(); j++)
        {
            if (primes[j] > i || i * primes[j] >= MAXN)
                break;
            sieve[i * primes[j]] = primes[j];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        int a = d + 1;
        while (sieve[a] != a)
            a++;
        int b = a + d;
        while (sieve[b] != b)
            b++;
        cout << (long long) a * b << "\n";
    }
    return 0;
}