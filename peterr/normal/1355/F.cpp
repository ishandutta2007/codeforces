#include <bits/stdc++.h>

using namespace std;

const long long MAXA = 1000000000000000000L;
const int MAXB = 1000000000;
const int MAXP = 700;
const int QUERIES = 16;
bool isComp[MAXP + 1];
vector<int> primes;
long long queries[QUERIES];
long long res[QUERIES];

int cntNum(long long q, int p)
{
    int ans = 0;
    while (q % p == 0)
    {
        ans++;
        q /= p;
    }
    return ans;
}

int main()
{
    for (int i = 2; i <= MAXP; i++)
    {
        if (!isComp[i])
            primes.push_back(i);
        for (int j = 0; j < (int) primes.size() && primes[j] * i <= MAXP; j++)
        {
            isComp[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    int ind = 0;
    for (int i = 0; i < QUERIES; i++)
    {
        //cout << "queery " << i << endl;
        long long cur = 1;
        while (1)
        {
            if (MAXA / primes[ind] < cur)
                break;
            //cout << primes[ind] << endl;
            cur *= primes[ind++];
        }
        queries[i] = cur;
    }
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < QUERIES; i++)
        {
            cout << "? " << queries[i] << endl;
            cin >> res[i];
        }
        int ans = 2;

        vector<pair<int, int>> extraQueries;
        for (int p : primes)
        {
            for (int i = 0; i < QUERIES; i++)
            {
                if (res[i] % p == 0)
                {
                    int q = p;
                    while ((long long) q * p <= MAXB)
                        q *= p;
                    extraQueries.push_back(make_pair(q, p));
                    break;
                }
            }
        }
        while (!extraQueries.empty())
        {
            long long q = extraQueries.back().first;
            int a = extraQueries.back().second;
            extraQueries.pop_back();
            bool sec = false;
            int b = 1;
            if (!extraQueries.empty())
            {
                sec = true;
                q *= extraQueries.back().first;
                b = extraQueries.back().second;
                extraQueries.pop_back();
            }
            cout << "? " << q << endl;
            long long ret;
            cin >> ret;
            ans *= cntNum(ret, a) + 1;
            if (sec)
                ans *= cntNum(ret, b) + 1;
        }
        ans = max(ans, 8);
        cout << "! " << ans << endl;
    }
    return 0;
}