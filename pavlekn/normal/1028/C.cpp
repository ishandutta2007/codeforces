#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> x;
    vector<pair<int, int>> y;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a.push_back({x1, y1});
        a.push_back({x2, y2});
        x.push_back({x1, 0});
        x.push_back({x2, 1});
        y.push_back({y1, 0});
        y.push_back({y2, 1});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<int> xx;
    vector<int> yy;
    int count_x = 0;
    int count_y = 0;
    for (auto p : x)
    {
        if (p.second == 0)
        {
            ++count_x;
        }
        else
        {
            --count_x;
        }
        if (count_x >= (n - 1))
        {
            xx.push_back(p.first);
        }
    }
    for (auto p : y)
    {
        if (p.second == 0)
        {
            ++count_y;
        }
        else
        {
            --count_y;
        }
        if (count_y >= (n - 1))
        {
            yy.push_back(p.first);
        }
    }
    for (auto cx : xx)
    {
        for (auto cy : yy)
        {
            int count = 0;
            for (int i = 0; i < n; ++i)
            {
                if (cx >= a[2 * i].first && cy >= a[2 * i].second && cx <= a[2 * i + 1].first && cy <= a[2 * i + 1].second)
                {
                    ++count;
                }
            }
            if (count >= (n - 1))
            {
                cout << cx << " " << cy;
                return 0;
            }
        }
    }
}