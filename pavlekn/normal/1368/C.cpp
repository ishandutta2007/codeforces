#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e3 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    ans.push_back({0, 0});
    ans.push_back({0, 1});
    ans.push_back({1, 0});
    ans.push_back({1, 1});
    for (int i = 0; i < n; ++i)
    {
        ans.push_back({i + 2, i + 2});
        ans.push_back({i + 1, i + 2});
        ans.push_back({i + 2, i + 1});
    }
    cout << ans.size() << endl;
    for (auto el : ans)
    {
        cout << el.first << " " << el.second << endl;
    }
    return 0;
}