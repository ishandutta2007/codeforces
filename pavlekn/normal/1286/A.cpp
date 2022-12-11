#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> t[2];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n, -1);
    vector<int> b;
    vector<int> c;
    vector<int> cnt(2);
    vector<int> us(n + 1);
    for (int i = 0; i < n; ++i)
    {
        int pos;
        cin >> pos;
        if (pos > 0)
        {
            us[pos] = true;
            pos %= 2;
            a[i] = pos;
            c.push_back(i);
            b.push_back(pos);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!us[i])
        {
            ++cnt[i % 2];
        }
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (b.size() == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    vector<int> used(n + 1);
    for (int i = 1; i < b.size(); ++i)
    {
        if (b[i] != b[i - 1])
        {
            ++ans;
            used[c[i]] = true;
        }
    }
    int pr = 0;
    int ff = false;
    int mm = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= 0)
        {
            if (!used[i])
            {
                int val = 2;
                if (pr == 0)
                {
                    val = 1;
                }
                t[a[i]].push_back({-val, i - pr});
            }
            mm = a[i];
            pr = i + 1;
        }
    }
    t[mm].push_back({-1, n - pr});
    sort(t[0].begin(), t[0].end());
    sort(t[1].begin(), t[1].end());
    for (auto el : t[0])
    {
        if (el.second <= cnt[0])
        {
            cnt[0] -= el.second;
        }
        else
        {
            ans -= el.first;
        }
    }
    for (auto el : t[1])
    {
        if (el.second <= cnt[1])
        {
            cnt[1] -= el.second;
        }
        else
        {
            ans -= el.first;
        }
    }
    cout << ans << endl;
    return 0;
}