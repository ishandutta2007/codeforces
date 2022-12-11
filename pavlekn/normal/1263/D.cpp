#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

vector<vector<int>> g(256);
int was[256];

void dfs(int u)
{
    was[u] = true;
    for (auto v : g[u])
    {
        if (!was[v])
        {
            dfs(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> used(256);
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (auto el : s)
        {
            used[el] = true;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = i + 1; j < s.size(); ++j)
            {
                g[s[i]].push_back(s[j]);
                g[s[j]].push_back(s[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 256; ++i)
    {
        if (used[i] && !was[i])
        {
            dfs(i);
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}