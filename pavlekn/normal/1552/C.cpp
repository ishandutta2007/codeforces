#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(k);
        vector<int> used(2 * n);
        for (int i = 0; i < k; ++i)
        {
            cin >> a[i].first >> a[i].second;
            --a[i].first; --a[i].second;
            used[a[i].first] = true;
            used[a[i].second] = true;
        }
        int ans = 0;
        for (int i = 0; i < k; ++i)
        {
            int A = a[i].first;
            int B = a[i].second;
            if (A > B)
            {
                swap(A, B);
            }
            int c = 0;
            for (int j = 0; j < 2 * n; ++j)
            {
                if (!used[j] && j > A && j < B)
                {
                    ++c;
                }
            }
            c = min(c, (n - k) * 2 - c);
            ans += c;
            for (int j = i + 1; j < k; ++j)
            {
                int cnt = 0;
                if (a[j].first > A && a[j].first < B)
                {
                    ++cnt;
                }
                if (a[j].second > A && a[j].second < B)
                {
                    ++cnt;
                }
                if (cnt == 1)
                {
                    ++ans;
                }
            }
        }
        for (int i = 1; i < n - k; ++i)
        {
            ans += i;
        }
        cout << ans << endl;
    }
    return 0;
}