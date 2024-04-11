#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); srand(clock());
    int n, m;
    cin >> n >> m;
    vector<int> xx(n + m);
    vector<int> t(n + m);
    vector<int> x1;
    vector<int> x2;
    for (int i = 0; i < n + m; ++i)
    {
        cin >> xx[i];
    }
    for (int i = 0; i < n + m; ++i)
    {
        cin >> t[i];
        if (t[i])
        {
            x2.push_back(xx[i]);
        }
        else
        {
            x1.push_back(xx[i]);
        }
    }
    int k = 0;
    vector<int> ans(m);
    for (int i = 0; i < n; ++i)
    {
        while (k != m - 1 && abs(x1[i] - x2[k]) > abs(x1[i] - x2[k + 1]))
        {
            ++k;
        }
        ++ans[k];
    }
    for (auto el : ans)
    {
        cout << el << " ";
    }
    return 0;
}