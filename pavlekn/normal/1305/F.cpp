#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<int> primes;
    vector<int> pr;
    for (int i = 2; i < 10000; ++i)
    {
        int fl = true;
        for (int j = 2; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                fl = false;
                break;
            }
        }
        if (fl)
        {
            primes.insert(i);
            pr.push_back(i);
        }
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        int mm = a[i];
        for (auto el : pr)
        {
            while (mm % el == 0)
            {
                mm /= el;
            }
        }
        if (mm > 1)
        {
            primes.insert(mm);
        }
    }
    random_shuffle(a.begin(), a.end());
    int ans = n;
    for (auto el : primes)
    {
        int cur = 0;
        for (int i = 0; i < n; ++i)
        {
            int d = el;
            int r = a[i] % el;
            if (r != a[i])
            {
                d = r;
            }
            d = min(d, el - r);
            cur += d;
            if (cur > ans)
            {
                break;
            }
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}