#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int SQRT = 320;
const int SQRT2 = 95;
int lp[MAXN + 1];
vector<int> primes;

int queryA(int a)
{
    cout << "A " << a << endl;
    int q;
    cin >> q;
    return q;
}

int queryB(int a)
{
    cout << "B " << a << endl;
    int q;
    cin >> q;
    return q;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (!lp[i])
        {
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int) primes.size() && primes[j] <= lp[i] && i * primes[j] <= n; j++)
        {
            lp[primes[j] * i] = primes[j];
        }
    }
    int ans = 1;
    for (int p : primes)
    {
        if (p > SQRT)
            break;
        queryB(p);
        if (queryA(p))
        {
            int temp = p;
            while ((long long) temp * p <= n && queryA(temp * p))
            {
                temp *= p;
            }
            ans *= temp;
        }
    }
    bool found = false;
    int cnt = 0;
    int ex = queryA(1);
    vector<int> window;
    for (int p : primes)
    {
        if (p <= SQRT)
            continue;
        cnt++;
        window.push_back(p);
        if (queryB(p) == 2)
        {
            ans *= p;
            break;
        }
        if (cnt == SQRT2)
        {
            ex -= cnt;
            cnt = 0;
            if (queryA(1) != ex)
            {
                found = true;
                for (int p2 : window)
                {
                    if (queryA(p2))
                    {
                        ans *= p2;
                    }
                }
                if (found)
                    break;
            }
            window.clear();
        }
    }
    if (!found && cnt)
    {
        ex -= cnt;
        cnt = 0;
        if (queryA(1) != ex)
        {
            for (int p2 : window)
            {
                if (queryA(p2))
                {
                    ans *= p2;
                }
            }
        }
        window.clear();
    }
    cout << "C " << ans << endl;
    return 0;
}