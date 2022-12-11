#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a = {};
    vector<pair<int, int>> b = {};
    int x1, y1;
    for (int i = 0; i < n; ++i)
    {
        cin >> x1 >> y1;
        int x = min(x1, y1);
        int y = max(x1, y1);
        a.push_back({x, y});
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> x1 >> y1;
        int x = min(x1, y1);
        int y = max(x1, y1);
        b.push_back({x, y});
    }
    int count = 0;
    set<int> s = {};
    int ch = 0;
    set<int> s1 = {};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            s = {};
            s.insert(a[i].first);
            s.insert(a[i].second);
            s.insert(b[j].first);
            s.insert(b[j].second);
            if (s.size() == 3)
            {
                if (a[i].first == b[j].second || a[i].first == b[j].first)
                {
                    ch = a[i].first;
                }
                if (a[i].second == b[j].second || a[i].second == b[j].first)
                {
                    ch = a[i].second;
                }
                s1.insert(ch);
            }
        }
    }
    if (s1.size() == 1)
    {
        cout << ch << endl;
        return 0;
    }
    int count1;
    int count2;
    int c1;
    int c2;
    for (int x = 1; x < 9; ++x)
    {
        for (int y = x + 1; y < 10; ++y)
        {
            count1 = 0;
            set<int> ans = {};
            int me;
            for (int z1 = 1; z1 < 9; ++z1)
            {
                for (int z2 = z1 + 1; z2 < 10; ++z2)
                {
                    s = {};
                    s.insert(x);
                    s.insert(y);
                    s.insert(z1);
                    s.insert(z2);
                    c1 = 0;
                    c2 = 0;
                    if (s.size() == 3)
                    {

                        if (x == z1 || x == z2)
                        {
                            me = x;
                        }
                        else
                        {
                            me = y;
                        }
                        for (int i = 0; i < n; ++i)
                        {
                            if ((a[i].first == x && a[i].second == y) || (a[i].first == y && a[i].second == x))
                            {
                                ++c1;
                            }
                        }
                        for (int i = 0; i < m; ++i)
                        {
                            if ((b[i].first == z1 && b[i].second == z2) || (b[i].first == z2 && b[i].second == z1))
                            {
                                ++c2;
                            }
                        }
                    }
                    if (c1 == 1 && c2 == 1)
                    {
                        ans.insert(me);
                    }
                }
            }
            if (ans.size() > 1)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for (int x = 1; x < 9; ++x)
    {
        for (int y = x + 1; y < 10; ++y)
        {
            count2 = 0;
            set<int> ans = {};
            int me;
            for (int z1 = 1; z1 < 9; ++z1)
            {
                for (int z2 = z1 + 1; z2 < 10; ++z2)
                {
                    s = {};
                    s.insert(x);
                    s.insert(y);
                    s.insert(z1);
                    s.insert(z2);
                    c1 = 0;
                    c2 = 0;
                    if (s.size() == 3)
                    {
                        if (x == z1 || x == z2)
                        {
                            me = x;
                        }
                        else
                        {
                            me = y;
                        }
                        for (int i = 0; i < n; ++i)
                        {
                            if ((a[i].first == z1 && a[i].second == z2) || (a[i].first == z2 && a[i].second == z1))
                            {
                                ++c1;
                            }
                        }
                        for (int i = 0; i < m; ++i)
                        {
                            if ((b[i].first == x && b[i].second == y) || (b[i].first == y && b[i].second == x))
                            {
                                ++c2;
                            }
                        }
                    }
                    if (c1 == 1 && c2 == 1)
                    {
                        ans.insert(me);
                    }
                }
            }
            if (ans.size() > 1)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
}