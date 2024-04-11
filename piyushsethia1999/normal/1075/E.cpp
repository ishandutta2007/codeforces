#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define int long long

using namespace std;

int manha(pair<int, int> p1, pair<int, int> p2)
{
    int di = 0;
    if (p1.x > p2.x)
        di = p1.x - p2.x;
    else
        di = p2.x - p1.x;
    if (p1.y > p2.y)
        di += p1.y - p2.y;
    else
        di += p2.y - p1.y;
    return di;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    vector<pair<int, int>> a(n); for (int o = 0; o < n; o++) { cin >> a[o].first >> a[o].second; }
    int maxx = -100000000;
    int minx = 100000000;
    int miny = 100000000;
    int maxy = -100000000;
    int complete = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        complete += manha(a[i], a[i + 1]);
    }
    complete += (manha(a[0], a[n - 1]));
    for (int i = 0; i < n; ++i)
    {
        maxy = max(maxy, a[i].y);
        maxx = max(maxx, a[i].x);
        miny = min(miny, a[i].y);
        minx = min(minx, a[i].x);
    }
    std::vector<std::vector<int> > mpp(4);
    for (int i = 0; i < n; ++i)
    {
        if (a[i].x == minx)
        {
            mpp[0].pb(i);
        }
        else if (a[i].y == maxy)
        {
            mpp[1].pb(i);
        }
        else if (a[i].x == maxx)
        {
            mpp[2].pb(i);
        }
        else if (a[i].y == miny)
        {
            mpp[3].pb(i);
        }
    }
    int siz = 0;
    int max3 = -1;
    for (int i = 0; i < 4; ++i)
    {
        siz += mpp[i].size();
    }
    if (siz > 2)
    {
        for (int i = 0; i < 4; ++i)
        {
            std::vector<int> pos;
            for (int j = 0; j < 4; ++j)
            {
                if (i != j)
                {
                    pos.pb(j);
                }
            }
            for (int j = 0; j < (1 << 6); ++j)
            {
                int cnt = 0;
                for (int k = 0; k < 6; ++k)
                {
                    if (j & (1 << k))
                    {
                        cnt++;
                    }
                }
                if (cnt != 2)
                {
                    continue;
                }
                std::vector<pair<int, int> > in;
                for (int k = 0; k < 6; ++k)
                {
                    if (j & (1 << k))
                    {
                        in.pb((k) / 2, k % 2);
                    }
                }
                int peri = 0;
                if ((mpp[pos[in[0].first]].size() <= in[0].second) || (mpp[pos[in[1].first]].size() <= in[1].second))
                {
                    continue;
                }
                int i1 = mpp[pos[in[0].first]][in[0].second];
                int i2 = mpp[pos[in[1].first]][in[1].second];
                for (int i3 = 0; i3 < n; ++i3)
                {
                    if (i1 != i3 && i2 != i3)
                    {
                        peri = 0;
                        peri += manha(a[i1], a[i2]);
                        peri += manha(a[i2], a[i3]);
                        peri += manha(a[i3], a[i1]);
                        max3 = max(max3, peri);
                    }
                }
            }
        }
    }
    if (max3 == -1)
        max3 = complete;
    cout << max3 << " ";
    for (int i = 4; i <= n; ++i)
    {
        cout << complete << " ";
    }
}