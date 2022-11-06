#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1E16;

long long manhattan(pair<long long, long long> a, pair<long long, long long> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    long long x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    long long xs, ys, t;
    cin >> xs >> ys >> t;
    vector<pair<long long, long long>> pts;
    while (x0 <= 2 * MAXN && y0 <= 2 * MAXN)
    {
        pts.push_back(make_pair(x0, y0));
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
    }
    int ans = 0;
    pair<long long, long long> spawn = make_pair(xs, ys);
    for (int i = 0; i < (int) pts.size(); i++)
    {
        pair<long long, long long> start = pts[i];
        long long dist = manhattan(start, spawn);
        if (dist <= t)
        {
            ans = max(ans, 1);
            if (dist + manhattan(start, pts[0]) <= t)
            {
                ans = max(ans, i + 1);
                for (int j = i + 1; j < (int) pts.size(); j++)
                {
                    if (dist + manhattan(start, pts[0]) + manhattan(pts[0], pts[j]) <= t)
                        ans = max(ans, j + 1);
                }
            }
            else
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (dist + manhattan(start, pts[j]) <= t)
                    {
                        ans = max(ans, i - j + 1);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}