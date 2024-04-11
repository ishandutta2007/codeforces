#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

vector<int> d, a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    d.resize(n);
    a.resize(m);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    int l = -1, r = n + 1;
    while (r - l > 1)
    {
        int med = (r + l) / 2;
        vector<int> x(m + 1, -1);
        for (int i = 0; i < med; i++)
            x[d[i]] = i;
        bool ok = true;
        for (int i = 1; i <= m; i++)
            if (x[i] == -1)
                ok = false;
        if (!ok)
        {
            l = med;
            continue;
        }
        vector< pair<int, int> > y;
        for (int i = 1; i <= m; i++)
            y.push_back(make_pair(x[i], i));
        sort(y.begin(), y.end());
        int sum = 0;
        for (int i = 0; i < y.size(); i++)
        {
            sum += a[y[i].second - 1] + 1;
            if (sum > y[i].first + 1)
                ok = false;
        }
        if (ok)
            r = med;
        else
            l = med;
    }
    if (r == n + 1)
        cout << -1;
    else
        cout << r;
    return 0;
}