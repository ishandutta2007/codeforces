#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN + 1];
int b[MAXN + 1];
int c[MAXN + 1];
int ans[MAXN + 1];
vector<int> where[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            where[i].clear();
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> c[i];
        }
        int last = -1;
        bool found = false;
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == c[m])
            {
                found = true;
                if (last == -1)
                    last = i;
                else if (b[i] != a[i])
                    last = i;
            }
        }
        if (!found)
        {
            cout << "NO\n";
            continue;
        }
        ans[m] = last;
        a[last] = b[last];
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == b[i])
                continue;
            where[b[i]].push_back(i);
        }
        for (int i = m - 1; i >= 1; i--)
        {
            if (where[c[i]].empty())
                ans[i] = last;
            else
            {
                ans[i] = where[c[i]].back();
                where[c[i]].pop_back();
            }
        }
        bool good = true;
        for (int i = 1; i <= n; i++)
        {
            if (!where[i].empty())
                good = false;
        }
        if (good)
        {
            cout << "YES\n";
            for (int i = 1; i <= m; i++)
                cout << ans[i] << " \n"[i == m];
        }
        else
            cout << "NO\n";
    }
    return 0;
}