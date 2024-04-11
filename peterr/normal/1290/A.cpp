#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3500;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        k = min(k, m - 1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> val(m);
        for (int i = 0; n - m + i < n; i++)
        {
            val[i] = max(a[i], a[n - m + i]);
            //cout << "HI " << i << " " << val[i] << endl;
        }
        int ptr = 0;
        deque<pair<int, int>> minSt;
        while (ptr < m - k)
        {
            while (!minSt.empty() && val[ptr] < minSt.back().first)
                minSt.pop_back();
            minSt.push_back(make_pair(val[ptr], ptr));
            ptr++;
        }
        int ans = minSt.front().first;
        int rem = 0;
        while (ptr < m)
        {
            while (!minSt.empty() && val[ptr] < minSt.back().first)
                minSt.pop_back();
            minSt.push_back(make_pair(val[ptr], ptr));
            if (minSt.front().second == rem)
                minSt.pop_front();
            rem++;
            ans = max(ans, minSt.front().first);
            ptr++;
        }
        cout << ans << "\n";
    }
    return 0;
}