#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<bool> del(n + 1, true);
        int cur = n;
        vector<int> roots;
        while (cur > 2)
        {
            roots.push_back(cur);
            del[cur] = false;
            int ptr = cur;
            while ((long long) (ptr - 1) * (ptr - 1) >= cur)
                ptr--;
            cur = ptr;
        }
        vector<pair<int, int>> ans;
        for (int i = 3; i <= n; i++)
        {
            if (!del[i])
                continue;
            ans.push_back({i, n});
        }
        for (int i = 0; i < (int) roots.size() - 1; i++)
        {
            ans.push_back({roots[i], roots[i + 1]});
            ans.push_back({roots[i], roots[i + 1]});
        }
        if (!roots.empty())
        {
            ans.push_back({roots.back(), 2});
            ans.push_back({roots.back(), 2});
        }
        cout << ans.size() << "\n";
        for (pair<int, int> pr : ans)
            cout << pr.first << " " << pr.second << "\n";
    }
    return 0;
}