#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    set<int> s = {};
    for (int i = 0; i < m; ++i)
    {
        s.insert(b[i]);
    }
    vector<int> ans = {};
    for (int i = 0; i < n; ++i)
    {
        if (s.find(a[i]) != s.end())
        {
            ans.push_back(a[i]);
        }
    }
    for (auto el : ans)
    {
        cout << el << " ";
    }
}