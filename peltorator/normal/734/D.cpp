#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

vector< pair<int, int> > B, r, q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    int a = 1e9, b = 1e9, c = 1e9, d = 1e9, e = -1e9, f = -1e9, g = -1e9, h = -1e9;
    for (int i = 0; i < n; i++)
    {
        char C;
        int x0, y0;
        cin >> C >> x0 >> y0;
        if (C != 'R')
            B.push_back(make_pair(x0, y0));
        if (C != 'B')
            r.push_back(make_pair(x0, y0));
        if (y0 == y)
        {
            if (x > x0)
                h = max(h, x0);
            else
                d = min(d, x0);
        }
        if (x0 == x)
        {
            if (y > y0)
                f = max(f, y0);
            else
                b = min(b, y0);
        }
        if (x + y == x0 + y0)
        {
            if (x > x0)
                g = max(g, x0);
            else
                c = min(c, x0);
        }
        if (y - y0 == x - x0)
        {
            if (y > y0)
                e = max(e, y0);
            else
                a = min(a, y0);
        }
    }
    for (int i = 0; i < B.size(); i++)
    {
        int x0 = B[i].first, y0 = B[i].second;
        if (x + y == x0 + y0 && (x0 == g || x0 == c))
        {
            cout << "YES";
            return 0;
        }
        if (y - y0 == x - x0 && (y0 == e || y0 == a))
        {
            cout << "YES";
            return 0;
        }
    }
    for (int i = 0; i < r.size(); i++)
    {
        int x0 = r[i].first, y0 = r[i].second;
        if (y0 == y && (h == x0 || d == x0))
        {
            cout << "YES";
            return 0;
        }
        if (x0 == x && (f == y0 || b == y0))
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}