#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int a[MAXN];
vector<int> where[MAXN + 1];
int ans[MAXN + 1];

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
        for (int i = 1; i <= n; i++)
            where[i].clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            where[a[i]].push_back(i);
        }
        fill(ans + 1, ans + n + 1, -1);
        int cur = n;
        for (int i = 1; i <= n; i++)
        {
            if (where[i].empty())
                continue;
            int k = max(where[i][0] + 1, n - where[i].back());
            for (int j = 0; j < (int) where[i].size() - 1; j++)
            {
                k = max(k, where[i][j + 1] - where[i][j]);
            }
            while (cur >= 1 && cur >= k)
                ans[cur--] = i;
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " \n"[i == n];
    }
    return 0;
}