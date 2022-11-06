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
        int n, x;
        cin >> n >> x;
        vector<pair<int, int>> v;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.push_back({a, 1});
            ans += a;
        }
        int ptr = 0;
        while (ptr < (int) v.size())
        {
            if (v[ptr].first % x)
                break;
            ans += (long long) v[ptr].first * v[ptr].second;
            v.push_back({v[ptr].first / x, (long long) x * v[ptr].second});
            ptr++;
        }
        cout << ans << "\n";
    }
    return 0;
}