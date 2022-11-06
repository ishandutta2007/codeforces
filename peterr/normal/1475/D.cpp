#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9;
const int MAXN = 2E5;
pair<int, int> a[MAXN];

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
        for (int i = 0; i < n; i++)
            cin >> a[i].first;
        for (int i = 0; i < n; i++)
            cin >> a[i].second;
        vector<int> v1;
        vector<int> v2;
        long long usage = 0;
        for (int i = 0; i < n; i++)
        {
            usage += a[i].first;
            if (a[i].second == 1)
                v1.push_back(a[i].first);
            else
                v2.push_back(a[i].first);
        }
        long long diff = m;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int cost = (int) v1.size();
        int ptr1 = 0;
        long long save = 0;
        for (int x : v1)
            save += x;
        int ans = INF;
        for (int i = 0; i <= (int) v2.size(); i++)
        {
            if (i)
            {
                cost += 2;
                save += v2[(int) v2.size() - i];
            }
            while (ptr1 < (int) v1.size() && (save - v1[ptr1]) >= diff)
            {
                cost--;
                save -= v1[ptr1];
                ptr1++;
            }
            if (save >= diff)
                ans = min(ans, cost);
        }
        if (ans == INF)
            ans = -1;
        cout << ans << "\n";

    }
    return 0;
}