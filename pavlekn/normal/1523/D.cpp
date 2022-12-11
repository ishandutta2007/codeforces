#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = (1LL << 15);

int cnt[MAXN];
int x[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        a[i] = 0;
        for (auto el : s)
        {
            a[i] *= 2ll;
            a[i] += el - '0';
        }
    }
    int ans = 0;
    int t = 37;
    vector<int> used(n);
    for (int _ = 0; _ < min(n, t); ++_)
    {
        int num = rng() % n;
        if (used[num])
        {
            for (int i = 0; i < n; ++i)
            {
                if (!used[i])
                {
                    num = i;
                    break;
                }
            }
        }
        used[num] = true;
        vector<int> cur;
        for (int i = 0; i < m; ++i)
        {
            if ((1LL << i) & a[num])
            {
                cur.push_back(i);
            }
        }
        for (int i = 0; i < MAXN; ++i)
        {
            x[i] = 0;
            cnt[i] = 0;
        }
        for (int i = 0; i < n; ++i)
        {
            int msk = 0;
            int nm = 0;
            for (auto el : cur)
            {
                if (a[i] & (1LL << el))
                {
                    msk |= (1LL << nm);
                }
                ++nm;
            }
            ++x[msk];
        }
        for (int i = 0; i < MAXN; ++i)
        {
            if (x[i] == 0)
            {
                continue;
            }
            for (int s = i; s; s = (s - 1) & i)
            {
                cnt[s] += x[i];
            }
        }
        for (int i = 0; i < MAXN; ++i)
        {
            if (cnt[i] == 0)
            {
                continue;
            }
            if (cnt[i] * 2 >= n)
            {
                if (__builtin_popcount(i) > __builtin_popcount(ans))
                {
                    ans = 0;
                    for (int j = 0; j < m; ++j)
                    {
                        if (i & (1LL << j))
                        {
                            ans += (1LL << cur[j]);
                        }
                    }
                }
            }
        }
    }
    vector<int> res(m);
    int nm = 0;
    while (ans > 0)
    {
        res[nm] = ans % 2ll;
        ans /= 2ll;
        ++nm;
    }
    reverse(res.begin(), res.end());
    for (auto el : res)
    {
        cout << el;
    }
    cout << endl;
    return 0;
}