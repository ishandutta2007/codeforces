#include <bits/stdc++.h>

using namespace std;

double s(int x1, int x2, int x3, int y1, int y2, int y3)
{
    double a = sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
    double b = sqrt(abs(x1 - x3) * abs(x1 - x3) + abs(y1 - y3) * abs(y1 - y3));
    double c = sqrt(abs(x3 - x2) * abs(x3 - x2) + abs(y3 - y2) * abs(y3 - y2));
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<pair<int, int>> a = {};
    vector<pair<int, int>> b = {};
    int x, y;
    for (int i = 0; i < 4; ++i)
    {
        cin >> x >> y;
        a.push_back({x, y});
    }
    for (int i = 0; i < 4; ++i)
    {
        cin >> x >> y;
        b.push_back({x, y});
    }
    string ans = "NO";
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (a[i].first == b[j].first && a[i].second == b[j].second)
            {
                ans = "YES";
            }
        }
    }
    for (int x = -100; x <= 100; ++x)
    {
        for (int y = -100; y <= 100; ++y)
        {
            if (abs(s(a[0].first, a[1].first, x, a[0].second, a[1].second, y) + s(a[2].first, a[1].first, x, a[2].second, a[1].second, y)
                     + s(a[2].first, a[3].first, x, a[2].second, a[3].second, y) + s(a[0].first, a[3].first, x, a[0].second, a[3].second, y)
                    - s(a[0].first, a[1].first, a[2].first, a[0].second, a[1].second, a[2].second) -
                     s(a[0].first, a[3].first, a[2].first, a[0].second, a[3].second, a[2].second)) < 0.00000001
                && abs(s(b[0].first, b[1].first, x, b[0].second, b[1].second, y) + s(b[2].first, b[1].first, x, b[2].second, b[1].second, y)
                     + s(b[2].first, b[3].first, x, b[2].second, b[3].second, y) + s(b[0].first, b[3].first, x, b[0].second, b[3].second, y)
                    - s(b[0].first, b[1].first, b[2].first, b[0].second, b[1].second, b[2].second) -
                     s(b[0].first, b[3].first, b[2].first, b[0].second, b[3].second, b[2].second)) < 0.00000001)
            {
                ans = "YES";
            }
        }
    }
    cout << ans << endl;
}