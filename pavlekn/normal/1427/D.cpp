#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        --a[i];
    }
    vector<vector<int>> ans;
    while (true)
    {
        int fl = true;
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
        {
            pos[a[i]] = i;
        }
        for (int i = 1; i < n; ++i)
        {
            if (a[i] < a[i - 1])
            {
                fl = false;
                break;
            }
        }
        if (fl)
        {
            break;
        }
        int num = 0;
        for (int i = 1; i < n; ++i)
        {
            if (pos[i] < pos[i - 1])
            {
                num = i;
                break;
            }
        }
        int cnt = num;
        while (cnt + 1 < n && pos[cnt + 1] == pos[cnt] + 1)
        {
            ++cnt;
        }
        vector<int> cur;
        if (pos[num] > 0)
        {
            cur.push_back(pos[num]);
        }
        cur.push_back(1 + cnt - num);
        cur.push_back(pos[num - 1] - pos[num] - (cnt - num));
        if (pos[num - 1] != n - 1)
        {
            cur.push_back(n - 1 - pos[num - 1]);
        }
        ans.push_back(cur);
        vector<int> b;
        int st = n - 1;
        for (int i = cur.size() - 1; i >= 0; --i)
        {
            for (int j = st - cur[i] + 1; j <= st; ++j)
            {
                b.push_back(a[j]);
            }
            st -= cur[i];
        }
        a = {};
        for (auto el : b)
        {
            a.push_back(el);
        }
    }
    cout << ans.size() << endl;
    for (auto el : ans)
    {
        cout << el.size() << " ";
        for (auto e : el)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}