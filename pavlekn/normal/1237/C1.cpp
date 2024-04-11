#include<bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, pair<int, int>>> a(n);
    for (int i = 0; i < n; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = {{x, y}, {z, i + 1}};
    }
    vector<int> used(n);
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            int ans = INF;
            int jj = 0;
            for (int j = 0; j < n; ++j)
            {
                if (!used[j])
                {
                    int x1 = a[i].first.first;
                    int x2 = a[j].first.first;
                    int y1 = a[i].first.second;
                    int y2 = a[j].first.second;
                    int z1 = a[i].second.first;
                    int z2 = a[j].second.first;
                    if (ans > (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1))
                    {
                        ans = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1);
                        jj = j;
                    }
                }
            }
            cout << a[i].second.second << " " << a[jj].second.second << endl;
            used[jj] = true;
        }
    }
    return 0;
}