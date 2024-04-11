#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAX = 4E7;
const int MAXF = 1E3;
int sieve[MAX];
int fac[MAXF];
int invFac[MAXF];

int modinv(int x)
{
    int ans = 1;
    int k = MOD - 2;
    while (k)
    {
        if (k & 1)
        {
            ans = (int) (((long long) ans * x) % MOD);
        }
        k >>= 1;
        x = (int) (((long long) x * x) % MOD);
    }
    return ans;
}

int choose(int n, int k)
{
    int ans = (int) (((long long) fac[n] * invFac[k]) % MOD);
    return (int) (((long long) ans * invFac[n - k]) % MOD);
}

int calc(multiset<long long> &s1, multiset<long long> &s2)
{
    long long prev = -1;
    int ans = 1;
    int cnt = 0;
    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        if (*it == prev)
            continue;
        prev = *it;
        long long target = *it;
        int diff = s1.count(target) - s2.count(target);
        if (diff > 0)
        {
            cnt += diff;
            ans = (int) (((long long) ans * choose(cnt, diff)) % MOD);
        }
    }
    return ans;
}

int main()
{
    fac[0] = invFac[0] = 1;
    for (int i = 1; i < MAXF; i++)
    {
        fac[i] = (int) (((long long) fac[i - 1] * i) % MOD);
        invFac[i] = modinv(fac[i]);
    }
    vector<int> primes;
    for (int i = 2; i < MAX; i++)
    {
        if (sieve[i] == 0)
        {
            sieve[i] = i;
            primes.push_back(i);
            if ((long long) i * i < MAX)
                for (int j = i * i; j < MAX; j += i)
                    sieve[j] = i;
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long d;
    cin >> d;
    int q;
    cin >> q;
    multiset<long long> div;
    vector<long long> divv;
    for (int x : primes)
    {
        if (d % x == 0)
            divv.push_back(x);
        while (d % x == 0)
        {
            d /= x;
            div.insert(x);
        }
    }
    if (d > 1)
    {
        div.insert(d);
        divv.push_back(d);
    }
    while (q--)
    {
        long long v, u;
        cin >> v >> u;
        multiset<long long> s1, s2;
        for (long long x : divv)
        {
            while (v % x == 0)
            {
                v /= x;
                s1.insert(x);
                //cout << "s1 " << x << endl;
            }
            while (u % x == 0)
            {
                u /= x;
                s2.insert(x);
               // cout << "s2 " << x << endl;
            }
        }
        int ans1 = calc(s1, s2);
        int ans2 = calc(s2, s1);
        int ans = (int) (((long long) ans1 * ans2) % MOD);
        cout << ans << "\n";
    }
    return 0;
}