#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MOD = 1E9 + 7;
int a[MAXN + 1];
map<int, int> fac[MAXN + 1];
map<int, multiset<int>> g;
map<int, int> cur;
int sieve[MAXN + 1];
vector<int> primes;

void check(int p, int n, int &ans)
{
    if ((int) g[p].size() < n)
        return;
    int num = *g[p].begin();
    int diff = num - cur[p];
    for (int i = 0; i < diff; i++)
        ans = (int) ((long long) ans * p % MOD);
    cur[p] = num;
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
            if (primes[j] > sieve[i] || primes[j] * i > MAXN)
                break;
            sieve[primes[j] * i] = primes[j];
        }
    }
    int n, q;
    cin >> n >> q;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while (a[i] > 1)
        {
            int p = sieve[a[i]];
            while (a[i] % p == 0)
            {
                fac[i][p]++;
                a[i] /= p;
            }
            g[p].insert(fac[i][p]);
            check(p, n, ans);
        }
    }
    while (q--)
    {
        int ind, x;
        cin >> ind >> x;
        while (x > 1)
        {
            int p = sieve[x];
            if (fac[ind].count(p))
                g[p].erase(g[p].find(fac[ind][p]));
            while (x % p == 0)
            {
                fac[ind][p]++;
                x /= p;
            }
            g[p].insert(fac[ind][p]);
            check(p, n, ans);
        }
        cout << ans << "\n";
    }
    return 0;
}