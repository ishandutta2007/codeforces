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
        long long t = (long long) (n - 1) * (n - 1);
        int mid = n / 2;
        for (int i = 2; i < n; i++)
        {
            int dist = 0;
            if (i > mid)
                dist = i - 1;
            else
                dist = n - i;
            t += (long long) dist * dist;
        }
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
        }
        vector<pair<int, int>> ans;
        ans.push_back({n, 1});
        swap(p[n], p[1]);
        for (int i = 2; i < n; i++)
        {
            if (i > mid)
            {
                swap(p[i], p[1]);
                ans.push_back({i, 1});
            }
            else
            {
                swap(p[i], p[n]);
                ans.push_back({i, n});
            }
        }
        cout << t << "\n";
        for (int x : p)
            if (x)
                cout << x << " ";
        cout << "\n";
        cout << ans.size() << "\n";
        while (!ans.empty())
        {
            cout << ans.back().first << " " << ans.back().second << "\n";
            ans.pop_back();
        }
    }
    return 0;
}