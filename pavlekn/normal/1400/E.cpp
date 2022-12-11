#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e3 + 225;

#define int long long

int solve(vector<int> & a)
{
    if (a.size() == 0)
    {
        return 0;
    }
    int n = a.size();
    int mn = a[0];
    for (int i = 0; i < n; ++i)
    {
        mn = min(mn, a[i]);
    }
    vector<int> cur;
    int s = mn;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != mn)
        {
            cur.push_back(a[i] - mn);
        }
        else
        {
            s += solve(cur);
            cur = {};
        }
    }
    s += solve(cur);
    return min(n, s);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << solve(a) << endl;
    return 0;
}