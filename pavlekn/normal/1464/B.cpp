#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18 + 118;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    int cnt1 = 0;
    int cnt0 = 0;
    int ans = INF;
    int cur = 0;
    for (auto el : s)
    {
        if (el == '0' || el == '?')
        {
            ++cnt0;
            cur += y * cnt1;
        }
        else
        {
            ++cnt1;
            cur += x * cnt0;
        }
    }
    ans = cur;
    int c1 = 0;
    int c0 = 0;
    for (auto el : s)
    {
        if (el == '0')
        {
            ++c0;
        }
        else if (el == '1')
        {
            ++c1;
        }
        else
        {
            cur -= c1 * y;
            cur += c0 * x;
            cur -= (cnt1 - c1) * x;
            cur += (cnt0 - c0 - 1) * y;
            --cnt0;
            ++cnt1;
            ++c1;
            ans = min(ans, cur);
        }
    }
    reverse(s.begin(), s.end());
    swap(x, y);
    cnt1 = 0;
    cnt0 = 0;
    cur = 0;
    for (auto el : s)
    {
        if (el == '0' || el == '?')
        {
            ++cnt0;
            cur += y * cnt1;
        }
        else
        {
            ++cnt1;
            cur += x * cnt0;
        }
    }
    c1 = 0;
    c0 = 0;
    for (auto el : s)
    {
        if (el == '0')
        {
            ++c0;
        }
        else if (el == '1')
        {
            ++c1;
        }
        else
        {
            cur -= c1 * y;
            cur += c0 * x;
            cur -= (cnt1 - c1) * x;
            cur += (cnt0 - c0 - 1) * y;
            --cnt0;
            ++cnt1;
            ++c1;
            ans = min(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}