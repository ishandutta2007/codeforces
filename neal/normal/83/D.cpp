#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int SIEVE = 1600000;

inline bool is_prime (int n)
{
    if (n == 2)
        return true;

    if (n < 2 || n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

bool prime [SIEVE];

void sieve ()
{
    memset (prime, true, sizeof (prime));
    prime [0] = prime [1] = false;

    for (int i = 2; i * i < SIEVE; i++)
        if (prime [i])
            for (int j = i * i; j < SIEVE; j += i)
                prime [j] = false;
}

vector <int> primes;

int pie (int pos, int count, int prod, int n)
{
    if (pos == (int) primes.size ())
        return (count % 2 == 0 ? 1 : -1) * (n / prod);
    else
        return pie (pos + 1, count, prod, n) + (primes [pos] <= n / prod ? pie (pos + 1, count + 1, prod * primes [pos], n) : 0);
}

int solve (int n, int k)
{
    if (n == 0)
        return 0;

    if (n < SIEVE && (long long) k * k > n)
    {
        int count = 0;

        for (int i = 1; i <= n; i++)
            if (i == 1 || (i > k && prime [i]))
                count++;

        return count;
    }
    else
    {
        primes.clear ();

        for (int i = 1; i <= k; i++)
            if (prime [i])
                primes.push_back (i);

        return pie (0, 0, 1, n);
    }
}

int main ()
{
    sieve ();

    int A, B, K;
    scanf ("%d %d %d", &A, &B, &K);

    if (!is_prime (K))
    {
        puts ("0");
        return 0;
    }

    printf ("%d\n", solve (B / K, K - 1) - solve ((A - 1) / K, K - 1));
    return 0;
}