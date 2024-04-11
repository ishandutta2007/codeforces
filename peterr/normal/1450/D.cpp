#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int a[MAXN];
vector<int> where[MAXN + 1];
int active[MAXN + 1];
vector<int> events[MAXN + 1];
int ans[MAXN + 1];
bool found[MAXN + 1];

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
        fill(ans + 1, ans + n + 1, 0);
        fill(found + 1, found + n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            events[i].clear();
            where[i].clear();
            active[i] = -1;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            where[a[i]].push_back(i);
        }
        set<int> s;
        s.insert(-1);
        s.insert(n);
        for (int i = 1; i <= n; i++)
        {
            for (int pos : where[i])
            {
                auto it = s.lower_bound(pos);
                it--;
                int lb = *it;
                int ub = *s.upper_bound(pos);
                active[i] = max(active[i], ub - lb - 1);
            }
            for (int pos : where[i])
            {
                s.insert(pos);
            }
            if (active[i] != -1)
            {
                events[active[i]].push_back(i);
            }
        }
        int ptr = 0;
        for (int i = n; i >= 1; i--)
        {
            for (int x : events[i])
            {
                found[x] = true;
            }
            while (ptr + 1 <= n && found[ptr + 1])
                ptr++;
            ans[i] = ptr == n - i + 1;
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i];
        cout << "\n";
    }
    return 0;
}