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
    vector<int> ind(n + 1);
    vector<vector<int>> b(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        --a[i];
        b[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i)
    {
        b[i].push_back(n + 1);
    }
    b[n].push_back(n + 2);
    int ans = 1;
    vector<int> x;
    vector<int> y;
    y.push_back(n);
    x.push_back(a[0]);
    ++ind[a[0]];
    for (int i = 1; i < n; ++i)
    {
        if (x.back() == a[i])
        {
            x.push_back(a[i]);
            ++ind[a[i]];
            continue;
        }
        if (y.back() == a[i])
        {
            y.push_back(a[i]);
            ++ind[a[i]];
            continue;
        }
        if (b[x.back()][ind[x.back()]] < b[y.back()][ind[y.back()]])
        {
            y.push_back(a[i]);
            ++ind[a[i]];
            if (a[i] != y[y.size() - 2])
            {
                ++ans;
            }
        }
        else
        {
            x.push_back(a[i]);
            ++ind[a[i]];
            if (a[i] != x[x.size() - 2])
            {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}