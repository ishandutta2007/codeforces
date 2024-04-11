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
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = 1;
    vector<int> x;
    vector<int> y;
    x.push_back(a[0]);
    for (int i = 1; i < n; ++i)
    {
        if (!y.empty() && i != n - 1 && y.back() == a[i + 1])
        {
            y.push_back(a[i]);
            if (y.size() == 1 || a[i] != y[y.size() - 2])
            {
                ++ans;
            }
            continue;
        }
        if (x.back() != a[i])
        {
            ++ans;
            x.push_back(a[i]);
        }
        else
        {
            y.push_back(a[i]);
            if (y.size() == 1 || a[i] != y[y.size() - 2])
            {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}