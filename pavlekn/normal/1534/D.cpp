#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 6;

vector<vector<int>> g(MAXN);


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    cout << "? 1" << endl;
    vector<pair<int, int>> ans;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> b;
    vector<int> c;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            b.push_back(i);
        }
        else
        {
            c.push_back(i);
        }
    }
    int B = b.size();
    int C = c.size();
    if (B < C)
    {
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 1)
            {
                ans.push_back({0, i});
            }
        }
        for (auto u : b)
        {
            cout << "? " << u + 1 << endl;
            for (int i = 0; i < n; ++i)
            {
                int x;
                cin >> x;
                if (x == 1)
                {
                    ans.push_back({u, i});
                }
            }
        }
    }
    else
    {
        for (auto u : c)
        {
            cout << "? " << u + 1 << endl;
            for (int i = 0; i < n; ++i)
            {
                int x;
                cin >> x;
                if (x == 1)
                {
                    ans.push_back({u, i});
                }
            }
        }
    }
    cout << "!" << endl;
    for (auto el : ans)
    {
        cout << el.first + 1 << " " << el.second + 1 << endl;
    }
    return 0;
}