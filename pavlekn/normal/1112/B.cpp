#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 2e18;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> t(k);
    vector<int> c(k);
    vector<int> cur(k);
    int num = 0;
    int cnt = 0;
    int m = 0;
    vector<int> ans(n);
    int it = 0;
    vector<int> used(k);
    vector<int> good;
    while (it <= 150 * n)
    {
        int me = 0;
        for (int i = 0; i < k; ++i)
        {
            if (used[i])
            {
                continue;
            }
            if (it == 0)
            {
                if (num >= n)
                {
                    used[i] = true;
                    ++cnt;
                }
                else
                {
                    t[i] = a[num];
                    c[i] = a[num];
                    cur[i] = num;
                    ++num;
                }
            }
            else
            {
                if (t[i] != 0)
                {
                    if (c[i] - t[i] + 1 == round(((double)m / (double)n) * 100.0))
                    {
                        ans[cur[i]] = true;
                    }
                    --t[i];
                }
                if (t[i] == 0)
                {
                    ++me;
                    if (num >= n)
                    {
                        used[i] = true;
                        ++cnt;
                    }
                    else
                    {
                        t[i] = a[num];
                        c[i] = a[num];
                        cur[i] = num;
                        ++num;
                    }
                }
            }
        }
        ++it;
        m += me;
        if (cnt == k)
        {
            break;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ans[i])
        {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}