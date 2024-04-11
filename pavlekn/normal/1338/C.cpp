#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 71;

int sz[MAXN];
int sm[MAXN];

int get(int ind, int n, int k)
{
    if (ind == 0)
    {
        return 0;
    }
    int ans = sz[ind] * k;
    n -= sm[ind];
    --n;
    if (k == 1)
    {
        return ans + n;
    }
    if (k == 2)
    {
        --ind;
        for (int i = 0; i < ind; ++i)
        {
            if ((n & (1ll << ((ind - 1 - i) * 2))) && (n & (1ll << ((ind - 1 - i) * 2 + 1))))
            {
                ans += (1ll << ((ind - 1 - i) * 2));
                n ^= (1ll << ((ind - 1 - i) * 2 + 1));
                n ^= (1ll << ((ind - 1 - i) * 2));
            }
            else if ((n & (1ll << ((ind - 1 - i) * 2))))
            {
                ans += (1ll << ((ind - 1 - i) * 2 + 1));
                n ^= (1ll << ((ind - 1 - i) * 2));
            }
            else if ((n & (1ll << ((ind - 1 - i) * 2 + 1))))
            {
                ans += (1ll << ((ind - 1 - i) * 2));
                ans += (1ll << ((ind - 1 - i) * 2 + 1));
                n ^= (1ll << ((ind - 1 - i) * 2 + 1));
            }
        }
        return ans;
    }
    if (k == 3)
    {
        --ind;
        for (int i = 0; i < ind; ++i)
        {
            if ((n & (1ll << ((ind - 1 - i) * 2))) && (n & (1ll << ((ind - 1 - i) * 2 + 1))))
            {
                ans += (1ll << ((ind - 1 - i) * 2 + 1));
                n ^= (1ll << ((ind - 1 - i) * 2 + 1));
                n ^= (1ll << ((ind - 1 - i) * 2));
            }
            else if ((n & (1ll << ((ind - 1 - i) * 2))))
            {
                ans += (1ll << ((ind - 1 - i) * 2 + 1));
                ans += (1ll << ((ind - 1 - i) * 2));
                n ^= (1ll << ((ind - 1 - i) * 2));
            }
            else if ((n & (1ll << ((ind - 1 - i) * 2 + 1))))
            {
                ans += (1ll << ((ind - 1 - i) * 2));
                n ^= (1ll << ((ind - 1 - i) * 2 + 1));
            }
        }
        return ans;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < 30; ++i)
    {
        sm[i + 1] = sm[i] + sz[i];
        sz[i + 1] = (1ll << (2 * i));
    }
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        int k = n % 3;
        if (k == 0)
        {
            k = 3;
        }
        n = (n + 2) / 3;
        int ind = 0;
        int cnt = 0;
        while (cnt < n)
        {
            ++ind;
            cnt += sz[ind];
        }
        cout << get(ind, n, k) << endl;
    }
    return 0;
}