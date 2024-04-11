#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("-O3")

const int MAXN = 1e5 + 25;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n <= 3)
    {
        cout << 0 << endl;
        return 0;
    }
    int t = 2;
    int mx = 0;
    for (int k = 2; k < n; ++k)
    {
        int cur = (n / k) * (k - 1);
        if (n % k)
        {
            cur += (n % k) - 1;
        }
        cur -= (k - 1);
        if (cur > mx)
        {
            mx = cur;
            t = k;
        }
    }
    vector<int> a;
    int cnt = 0;
    for (int i = 1; i < n; ++i)
    {
        if (cnt < t - 1)
        {
            a.push_back(i);
            ++cnt;
        }
        else
        {
            cnt = 0;
        }
    }
    vector<int> used(n + 1);
    for (int _ = 0; _ < 1111; ++_)
    {
        vector<int> b;
        for (auto el : a)
        {
            if (!used[el])
            {
                b.push_back(el);
            }
        }
        if (b.size() < t)
        {
            break;
        }
        cout << t << " ";
        for (int i = 0; i < t; ++i)
        {
            cout << b[i] << " ";
            used[b[i]] = true;
        }
        cout << endl;
        int pos;
        cin >> pos;
        for (int i = 0; i < t; ++i)
        {
            used[pos] = false;
            ++pos;
            if (pos == n + 1)
            {
                pos = 1;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}