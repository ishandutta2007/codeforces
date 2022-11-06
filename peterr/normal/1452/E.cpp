#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
pair<int, int> a[MAXN];

int inter(int l, int r, int ind)
{
    int left = max(l, a[ind].first);
    int right = min(r, a[ind].second);
    return max(0, right - left + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    int ans = 0;
    for (int i = 1; i + k - 1 <= n; i++)
    {
        int temp = 0;
        vector<pair<int, int>> events;
        for (int j = 0; j < m; j++)
        {
            int len = a[j].second - a[j].first + 1;
            int x = inter(i, i + k - 1, j);
            temp += x;
            if (x == min(k, a[j].second - a[j].first + 1))
                continue;
            if (x == 0)
            {
                events.push_back(make_pair(a[j].first - k, 1));
                if (len >= k)
                {
                    events.push_back(make_pair(a[j].first, -1));
                    events.push_back(make_pair(a[j].second - k + 1, -1));
                }
                else
                {
                    events.push_back(make_pair(a[j].second - k + 1, -1));
                    events.push_back(make_pair(a[j].first, -1));
                }
                events.push_back(make_pair(a[j].second + 1, 1));
            }
            else
            {
                events.push_back(make_pair(a[j].first - k + x, 1));
                if (len >= k)
                {
                    events.push_back(make_pair(a[j].first, -1));
                    events.push_back(make_pair(a[j].second - k + 1, -1));
                }
                else
                {
                    events.push_back(make_pair(a[j].second - k + 1, -1));
                    events.push_back(make_pair(a[j].first, -1));
                }
                events.push_back(make_pair(a[j].second + 1 - x, 1));
            }
        }
        if (!events.empty())
        {
            sort(events.begin(), events.end());
            int p = 0;
            int pos = events[0].first;
            int slope = 0;
            int val = 0;
            int mx = 0;
            while (p < (int) events.size())
            {
                int newpos = events[p].first;
                val += (newpos - pos) * slope;
                pos = newpos;
                mx = max(mx, val);
                while (p < (int) events.size() && events[p].first == newpos)
                {
                    slope += events[p].second;
                    p++;
                }
            }
            temp += mx;
        }
        ans = max(ans, temp);
    }
    cout << ans << "\n";
    return 0;
}