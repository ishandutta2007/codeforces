#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
int a[MAXN + 1];
int ans[MAXN + 2];
vector<int> from[MAXN + 2];

bool isValid(int l, int r)
{
    for (int i = l + 1; i < r; i++)
    {
        if (a[i] == -1)
            continue;
        if (a[i] > r)
            return false;
        if (!isValid(i, a[i]))
            return false;
        i = a[i] - 1;
    }
    return true;
}

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
        {
            cin >> a[i];
        }
        bool valid = true;
        int ptr = 1;
        while (ptr < n)
        {
            if (a[ptr] != -1)
            {
                if (!isValid(ptr, a[ptr]))
                    valid = false;
                ptr = a[ptr];
            }
            else
                ptr++;
        }
        if (!valid)
            cout << -1 << "\n";
        else
        {
            for (int i = 1; i <= n + 1; i++)
                from[i].clear();
            for (int i = 1; i <= n; i++)
            {
                if (a[i] != -1)
                {
                    from[a[i]].push_back(i);
                }
            }
            int cur = n;
            int ind = n + 1;
            fill(ans + 1, ans + n + 1, 0);
            ans[n + 1] = n + 1;
            while (ind >= 1)
            {
                if (!from[ind].empty())
                {
                    if (!ans[ind])
                        ans[ind] = cur--;
                    for (int x : from[ind])
                        ans[x] = cur--;
                }
                ind--;
            }
            int cnt = 1;
            for (int i = 1; i <= n; i++)
                if (!ans[i])
                    ans[i] = cnt++;
            for (int i = 1; i <= n; i++)
            {
                cout << ans[i] << " \n"[i == n];
            }
        }
    }
    return 0;
}