#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int LOGN = 20;
int a[MAXN + 1];
vector<int> primes;
int sieve[MAXN + 1];
vector<int> factors[MAXN + 1];
int nxt[LOGN][MAXN + 1];

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
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while (a[i] > 1)
        {
            factors[i].push_back(sieve[a[i]]);
            a[i] /= sieve[a[i]];
        }
    }
    set<int> seen;
    int ptr = 0;
    for (int i = 1; i <= n; i++)
    {
        while (ptr < n)
        {
            bool valid = true;
            for (int p : factors[ptr + 1])
            {
                if (seen.count(p))
                    valid = false;
            }
            if (valid)
            {
                for (int p : factors[ptr + 1])
                {
                    seen.insert(p);
                }
                ptr++;
            }
            else
                break;
        }
        nxt[0][i] = ptr;
        for (int p : factors[i])
            seen.erase(p);
    }
    for (int i = 1; i < LOGN; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (nxt[i - 1][j] == n || nxt[i - 1][j] == -1)
                nxt[i][j] = -1;
            else
                nxt[i][j] = nxt[i - 1][nxt[i - 1][j] + 1];
        }
    }
    /*
    for (int i = 0; i < LOGN; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << "nxt " << i << " " << j << " " << nxt[i][j] << endl;
    }
    */
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = LOGN - 1; i >= 0; i--)
        {
            while (l <= r && nxt[i][l] != -1 && nxt[i][l] <= r)
            {
                l = nxt[i][l] + 1;
                ans += 1 << i;
            }
        }
        while (l <= r)
        {
            l = nxt[0][l] + 1;
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}