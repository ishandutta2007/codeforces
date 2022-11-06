#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, vector<int> &b)
{
    if (a.empty() || b.empty())
        return 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p = 0;
    int q = 0;
    int n = (int) a.size();
    int m = (int) b.size();
    vector<pair<int, int>> events;
    vector<bool> seen(m);
    int ans = 0;
    while (p < n && q < m)
    {
        if (a[p] == b[q])
        {
            seen[q] = true;
            events.push_back({0, 1});
            events.push_back({b[q], -1});
            p++;
            q++;
        }
        else if (a[p] > b[q])
        {
            if (p && !seen[q])
            {
                events.push_back({b[q] - p, 1});
                events.push_back({b[q], -1});
            }
            q++;
        }
        else
            p++;
    }
    while (q < m)
    {
        events.push_back({b[q] - p, 1});
        events.push_back({b[q], -1});
        q++;
    }
    int cur = 0;
    sort(events.rbegin(), events.rend());
    while (!events.empty())
    {
        int t = events.back().first;
        while (!events.empty() && events.back().first == t)
        {
            cur += events.back().second;
            events.pop_back();
        }
        ans = max(ans, cur);
    }
    return ans;
}

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
        vector<int> ap;
        vector<int> an;
        vector<int> bp;
        vector<int> bn;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x > 0)
                ap.push_back(x);
            else
                an.push_back(-x);
        }
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            if (x > 0)
                bp.push_back(x);
            else
                bn.push_back(-x);
        }
        cout << solve(ap, bp) + solve(an, bn) << "\n";
    }
    return 0;
}